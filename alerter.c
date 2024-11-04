#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 200;
}

int networkAlert(float celcius) {
    if(celcius <= 200)
    {
        return 200;
    }
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 500;
}

void alertInCelcius(float farenheit, int (*networkAlertFunc)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertFunc(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

int main() {

    alertInCelcius(150.0, &networkAlert); 
    alertInCelcius(305.0, &networkAlert);

    alertInCelcius(150.0, &networkAlertStub); 
    alertInCelcius(305.0, &networkAlertStub);
    assert(alertFailureCount == 1); 

    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
