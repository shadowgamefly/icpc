#include <iostream>
#include <cmath>
#include <algorithm>
#define F first
#define S second
#define MP make_pair

using namespace std;

typedef pair<double, double> pdd;

double length(const pdd& a){
    return sqrt(a.F * a.F + a.S * a.S);
}

pdd unit(const pdd& a){
    double len = length(a);
    return MP(a.F / len, a.S / len);
}

pdd b_perp_towards_a(const pdd &a, const pdd &b){
    double cross = a.F * b.S - a.S * b.F;
    if (abs(cross - 0) < 1e-13) return MP(a.F, a.S);
    else return MP(b.S * cross, -b.F * cross);
}

pdd triangle_vertex(pdd v1, pdd v2, double l1, double l2){
    pdd base = MP(v2.F -  v1.F, v2.S - v1.S);
    pdd u1 = unit(base); // parallel unit vec
    pdd u2 = unit(b_perp_towards_a(MP(1, 0), base)); // perpendicular unit vec in the direction of (1,0)

    double l0 = length(base);
    double semi_perim = (l0 + l1 + l2) / 2;
    double area = sqrt(semi_perim * (semi_perim - l0) * (semi_perim - l1) * (semi_perim - l2));
    double height = (area + area) / l0;
    double l1_base = sqrt(l1 * l1 - height * height);
    pdd vertex = MP(v1.F + l1_base * u1.F + height * u2.F,
                    v1.S + l1_base * u1.S + height * u2.S);
    return vertex;
}

int n;
double ans, l[10];
bool vis[10];
void update( int i, pdd v1, pdd v2){
    if (i >= n - 1) return;
    // we don't need to pick mirror for the first triangle because of symmetricality
    // also, we don't need to pick which side to extend because it is included in the permutation
    // --- always choose v2 and v3 as the new sides, and remember to try v2, v3 in both orders in order to find
    // both solutions of the triangle with v2, v3 as its base.
    pdd v3 = triangle_vertex(v1, v2, l[i], l[i+1]);
    ans = max(ans, v3.F);
    update( i + 2, v1, v3);
    update( i + 2, v3, v1);
    update( i + 2, v2, v3);
    update( i + 2, v3, v2);
}

int main(){
    cin >> n;
    for (int i =0 ; i < n; i++) cin >> l[i];
    sort(l, l+n);
    do{
        pdd v = triangle_vertex(MP(0,0), MP(0, l[0]), l[1], l[2]);
        ans = max(ans, v.F);
        update( 3, MP(0, l[0]) , v);
    }while (std::next_permutation(l, l + n));
    cout.precision(20);
    cout << ans << endl;

}
