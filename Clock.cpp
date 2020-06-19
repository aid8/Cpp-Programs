//Link: https://www.facebook.com/ProgrammerLang/photos/a.467124023782044/623440718150373/?type=3&eid=ARCvGGEzk4N7ziDHz1cEwb6M2n_I0wR4OXYxU-u2lu2Ajzpmn0xccbLQMNssMOGf32mNFD6jkwtK_zV9&__xts__%5B0%5D=68.ARDIA4-ZEkoxovWYB5sxhW7jPbZ7KEIVsnfAchCmioIna_OmQMnx9ZpXi_nCjVL02ujUMSTJeLnLpgz3lNRMmgdDbl3AQyYZ2RuEAbyLoq_JXK2aCdnNCY5hZWZ4aCWvDSK-3Phh8yIYEp0vjtidlnDg4wPT-Gr4lSZHvBxpddXxDC0Q3cjAm2iOOfsSUhZDwjXXC6rQW_7fqC7ZeEraFHY6JSi0ui4yq1bi-sGGHwUeTsBVwjsq5V2hCW3JzJg5vfIqE76J0uMTnN7m22BP2X2CgaQx_zTenoeyqoqeihx0mL6QETEmjqB4pviXlcDCSbJ3B0ZzOtwQ9hGWJxPoEAWFPDYGRWBVyKaIygnavFf2e09P6lf64aBnp7oET-78COk7btyTm5iU8eB_AmUa8HfYHFlZOjODnej4ByNEMr_JmLhakqZ7PfOk31fW31wK2Ynw53ct0j9oswcNkvt9M2DG4O_alUxGVDvr-o_cE-3DU35YHkT2SMBieQ&__tn__=EEHH-R
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Number of turns: "; cin >> n;
    if(n > 0) cout << "Output " << n%12;
    else cout << "Output " <<(n%-12) + 12;
    return 0;
}
