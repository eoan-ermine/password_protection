#ifndef PASS_PROTECTION_VALIDATORS_H
#define PASS_PROTECTION_VALIDATORS_H

#include <QString>

class PassValidator {
public:
    PassValidator(const QString& pass);
    bool validate();
    const QString& getErrorMessage();
private:
    const QString& pass;
    QString errorMessage;
};

#endif //PASS_PROTECTION_VALIDATORS_H
