#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

int counter = 0;

// 1. Carrega o dicionário do Linux para um Set (busca O(1))
unordered_set<string> carregarDicionario(const string& caminho) {
    unordered_set<string> palavras;
    ifstream arquivo(caminho);
    string linha;

    if (!arquivo.is_open()) {
        cerr << "Erro: Não foi possível abrir " << caminho << endl;
        return palavras;
    }

    while (getline(arquivo, linha)) {
        // Remove espaços ou caracteres de nova linha e converte para minúsculo
        transform(linha.begin(), linha.end(), linha.begin(), ::tolower);
        palavras.insert(linha);
    }
    return palavras;
}

bool filter(string s){
    bool found_y;
    forn(i, 0, sz(s)) if(s[i] == 'y') found_y = true;
    return true;
}

// 2. Função recursiva para testar todas as combinações
void encontrarCombinacoes(const vector<string>& possibilidades, 
                          const unordered_set<string>& dicionario, 
                          string palavraAtual, 
                          int indicePosicao) {
    
    // Se chegamos ao fim da palavra, verificamos se ela existe no dicionário
    if (indicePosicao == possibilidades.size()) {
        if (dicionario.find(palavraAtual) != dicionario.end()) {
            if(!filter(palavraAtual)) return;
            cout << "Encontrada: " << palavraAtual << endl;
            counter++;
        }
        return;
    }

    // Tenta cada letra possível para a posição atual
    for (char letra : possibilidades[indicePosicao]) {
        encontrarCombinacoes(possibilidades, dicionario, palavraAtual + (char)tolower(letra), indicePosicao + 1);
    }
}

int main() {
    cout << "Carregando dicionário... " << endl;
    unordered_set<string> dicionario = carregarDicionario("/usr/share/dict/words");
    cout << "Dicionário carregado com " << dicionario.size() << " palavras." << endl;

    vector<string> minhasPossibilidades = {
        "rtdghlmn",
        "aeiouhry",
        "fnsomrau",
        "aeioupgt",
        "cglnorst",
        "nltaeioh",
        "cedstolu",
        "tyhesnrk"
    };

    cout << "--- Palavras Válidas Encontradas ---" << endl;
    encontrarCombinacoes(minhasPossibilidades, dicionario, "", 0);

    cout << counter << endl;
    return 0;
}