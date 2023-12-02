#include "validators.h"

PassValidator::PassValidator(const QString &pass): pass(pass) { }

bool PassValidator::validate() {
    if (pass.length() < 6) {
        errorMessage = "Пароль должен содержать шесть или больше символов";
        return false;
    }

    bool lower_latin = true;
    for (QChar x: pass) {
        if (!(x >= 'a' && x <= 'z')) {
            lower_latin = false;
            break;
        }
    }

    if (!lower_latin) {
        errorMessage = "Пароль должен состоять исключительно из строчных латинских букв";
        return false;
    }

    return true;
}

const QString& PassValidator::getErrorMessage() {
    return errorMessage;
}
