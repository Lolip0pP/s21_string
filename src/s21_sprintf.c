#include "s21_sprintf.h"

const char *fl_opt = "-+ #0";
const int flags_opt_val[] = {F_L_ALIGNMENT, F_PLUS, F_SPACE, F_POINT, F_ZERO};

const char *fl_sz = "hlL";
const int flags_sz_val[] = {F_SHORT, F_LONG_I, F_LONG_D};

int s21_sprintf(char *result, const char *format, ...) {
    int lenght = 0;
    setup_t setup;
    va_list params;
    va_start(params, format);

    for (int cur = 0; format[cur] != '\0'; cur++) {

        if (format[cur] == '%') {
            setup = get_setup(&cur, format, &params);

            if (format[cur] == 'n')
                *(va_arg(params, int*)) = lenght;
            else
                lenght += read_specifier(result + lenght, format[cur], setup, &params);
        }
        else {
            result[lenght++] = format[cur];
            result[lenght] = '\0';
        }
    } 

    va_end(params);
    result[lenght] = '\0';

    return lenght;
}

setup_t get_setup(int *cur, const char *format, va_list *params) {
    setup_t setup = {.accuracy = -1};

    for (*cur += 1; s21_strchr(fl_opt, format[*cur]); *cur += 1)
        setup.flags |= flags_opt_val[s21_strchr(fl_opt, format[*cur]) - fl_opt];

    for (; s21_strchr("0123456789", format[*cur]); *cur += 1)
        setup.width = (setup.width * 10) + (format[*cur] - '0');

    for (; format[*cur] == '*'; *cur += 1)
        setup.width = va_arg(*params, int);

    if (format[*cur] == '.') {
        *cur += 1;

        setup.accuracy = 0;
        setup.flags |= F_ACCURACY;

        for (; s21_strchr("0123456789", format[*cur]); *cur += 1) 
            setup.accuracy = (setup.accuracy * 10) + (format[*cur] - '0');

        for (; format[*cur] == '*'; *cur += 1)
            setup.accuracy = va_arg(*params, int);
    }

    for (; s21_strchr(fl_sz, format[*cur]); *cur += 1)
        setup.type |= flags_sz_val[s21_strchr(fl_sz, format[*cur]) - fl_sz];

    return setup;
}

int read_specifier(char *result, char spec, setup_t setup, va_list *params) {
    int length = 0;
    long double arg = 0;
    long double (*get_arg)(va_list*, int type) = NULL;

    if (setup.accuracy == -1) setup.accuracy = get_accuracy(spec);

    if (s21_strchr("upoxX", spec)) setup.type |= F_UNSIGNED;

    if (spec < 'Z') setup.flags |= F_UPP;

    if (s21_strchr("diuxXop", spec))
        get_arg = get_int;
    else if (s21_strchr("fgGeE", spec))
        get_arg = get_double, setup.flags |= (F_FLOAT | F_START);

    if (spec == 'c') {}
    else if (spec == 's') {}
    else if (s21_strchr("xX", spec))
        setup.flags |= F_HEX;
    else if (spec == 'o')
        setup.flags |= F_OCT;
    else if (spec == 'p')
        setup.flags |= (F_HEX | F_POINT), setup.type = F_LONG_I;
    else if (s21_strchr("eE", spec))
        setup.flags |= F_MANTISSA;
    else if (s21_strchr("gG", spec)) {
        setup.flags |= F_GEN | (setup.flags & F_POINT ? 0 : F_COMPACT);
        setup.accuracy += !setup.accuracy ? 1 : 0;
    }

    if (get_arg) arg = get_arg(params, setup.type);

    if (spec == '%') 
        result[length++] = '%';
    else if (spec == 'c')
        length = read_c(result, setup, params);
    else if (spec == 's')
        length = read_s(result, setup, params);
    else
        length += read_arg(result + length, setup, arg);
    
    if (setup.flags & F_ZERO && (!(setup.flags & F_ACCURACY && !(setup.flags & F_FLOAT)) || s21_strchr("cs%", spec)))
        length = format(result + (s21_strchr("+- ", *result) && !s21_strchr("sc", spec) ? 1 : 0), length, setup.width, setup.flags, '0');
    
    length = format(result, length, setup.width, setup.flags, ' ');

    return length;
}

long double get_double(va_list *params, int type) {
    return type & F_LONG_D ? va_arg(*params, long double) : va_arg(*params, double);
}

long double get_int(va_list *params, int type) {
    long double result = 0;

    if (type & F_LONG_I && type & F_UNSIGNED)
        result = va_arg(*params, long unsigned int);
    else if (type & F_LONG_I)
        result = va_arg(*params, long int);
    else if (type & F_SHORT && type & F_UNSIGNED)
        result = va_arg(*params, unsigned int);
    else if (type & F_SHORT)
        result = va_arg(*params, int);
    else if (type & F_UNSIGNED)
        result = va_arg(*params, unsigned int);
    else
        result = va_arg(*params, int);

    return result;
}

int get_accuracy(char spec) {
    int accuracy = 0;

    s21_strchr("diouxXp", spec) ? accuracy = 1 : 0;
    s21_strchr("eEfgG", spec) ? accuracy = 6 : 0;

    return accuracy;
}

int format(char *str, int length, int width, int flags, char ch) {
    int padding = width - length;

    if (padding > 0) {
        if (flags & F_L_ALIGNMENT) {
            s21_memset(str + length, ch, padding);
            str[width] = '\0';
        } else {
            char temp[width + 1];
            s21_memset(temp, ch, padding);
            s21_strncpy(temp + padding, str, s21_strlen(str));
            s21_strncpy(str, temp, s21_strlen(temp));
        }
    }

    return padding > 0 ? width : length;
}

int read_c(char *str, setup_t setup, va_list *params) {
    if (setup.type & F_LONG_I) {
        wchar_t wc = va_arg(*params, wchar_t);
        wcstombs(str, &wc, 512);
    }
    else
        *str = va_arg(*params, int);

    return 1;
}

int read_s(char *str, setup_t setup, va_list *params) {
    if (setup.type & F_LONG_I)
        wcstombs(str, va_arg(*params, wchar_t *), 512);
    else
        s21_strcat(str, va_arg(*params, char *));

    int length = (int)s21_strlen(str);

    if (setup.accuracy & F_ACCURACY && length > setup.accuracy)
        length = setup.accuracy, str[length] = '\0';

    return length;
}

int read_arg(char *str, setup_t setup, long double arg) {
    int start_accuracy = setup.accuracy;
    int length = 0;

    if (arg < 0) 
        str[length++] = '-', setup.flags |= F_MINUS, arg = -arg;
    else if (setup.flags & F_PLUS) 
        str[length++] = '+';
    else if (setup.flags & F_SPACE)
        str[length++] = ' ';

    unsigned long int r_arg = arg;
    
    if (setup.flags & F_ACCURACY && setup.accuracy == 0 && r_arg == 0) {
        return length;
    }

    int log = setup.flags & (F_GEN | F_MANTISSA) ? r_log(arg) : 0;

    if (setup.flags & F_FLOAT)
        r_arg = roundl(arg * pow(10, setup.accuracy - log - (setup.flags & F_GEN ? 1 : 0)));

    if (setup.flags & F_GEN) {
        setup.accuracy -= log + 1;

        if (log < r_log(r_arg * pow(10, -setup.accuracy)))
            r_arg /= 10, setup.accuracy--, log++;

        if (!(log < start_accuracy && log >= -4))
            setup.flags |= F_MANTISSA, setup.accuracy += log;
    }

    if (setup.flags & F_COMPACT)
        for (; r_arg % 10 == 0 && setup.accuracy > 0; r_arg /= 10) setup.accuracy--;

    if (!(setup.flags & (F_FLOAT | F_ACCURACY)) && setup.flags & F_ZERO)
        setup.accuracy = setup.width - (setup.flags & (F_MINUS | F_PLUS | F_SPACE) ? 1 : 0);

    num_to_string(str, r_arg, &length, setup.accuracy, setup.flags);

    if (setup.flags & F_MANTISSA) 
        length += mantissa(str + length, setup, log);

    return length;
}

void num_to_string(char *str, unsigned long int num, int *index, int accuracy, unsigned int flags) {
    int remains = num % (flags & F_OCT ? 8 : flags & F_HEX ? 16 : 10);

    num /= flags & F_OCT ? 8 : flags & F_HEX ? 16 : 10;

    if (num > 0)
        num_to_string(str, num, index, accuracy - 1, flags & ~F_START);
    else if (accuracy > 0 || flags & F_HEX || flags & F_OCT) {
        if (flags & F_FLOAT) str[(*index)++] = '0', str[(*index)++] = '.';

        if (flags & F_HEX && flags & F_POINT) str[(*index)++] = '0', str[(*index)++] = flags & F_UPP ? 'X' : 'x', accuracy -= 2;

        if (flags & F_OCT && flags & F_POINT) str[(*index)++] = '0', accuracy -= 1;

        if (accuracy > 0) s21_memset(str + *index, '0', accuracy - 1), *index += accuracy - 1;
    }

    str[(*index)++] = remains + (remains < 10 ? '0' : flags & F_UPP ? 'A' - 10 : 'a' - 10);

    if ((!accuracy && flags & F_FLOAT) && (flags & F_POINT || !(flags & F_START))) str[(*index)++] = '.';
}

int r_log(long double arg) { return arg ? (int)floorl(log10l(arg)) : 0; }

int mantissa(char *str, setup_t setup, int log) {
    *str++ = setup.flags & F_UPP ? 'E' : 'e';

    int flags = F_ZERO + F_PLUS + (setup.flags & F_UPP ? F_UPP : 0);
    
    return read_arg(str, (setup_t){flags, 0, 2, 0}, log) + 1;
}
