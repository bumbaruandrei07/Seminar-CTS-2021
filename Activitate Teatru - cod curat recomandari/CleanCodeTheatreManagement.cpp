
//Clean Code - recomandari utilizate:

// Comentarii redundante eliminate
// Cresterea vizibilitatii codulului


#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Teatru{
protected:
	const int idT; 
	static int contorT; 
	char* tipTeatru; 
	string adresaTeatru; 
	float* nrSpectacolePromovateZilnic;
	float* nrSpectacolePromovate;
	int zile; 
	int Spectacole;
	bool deschis;
	int oraDeschis[7];

public:

#pragma region Constructori

	Teatru() :idT(Teatru::contorT){
		this->tipTeatru = new char[strlen("Teatru de comedie") + 1];
		strcpy(tipTeatru, "Teatru de comedie");
		this->adresaTeatru = "B-dul Gheorghe Magheru";
		this->deschis = true;
		this->zile = 0;
		this->nrSpectacolePromovate = NULL;
		this->Spectacole;
		for (int i = 0; i < 7; i++){
			if (i < 5)
				this->oraDeschis[i] = 8;
			else
				this->oraDeschis[i] = 10;
		}
		Teatru::contorT++;
	}

	Teatru(char* tipTeatruT, string adresaTeatruT, int zileT, float* nrSpectacolePromovateT, float* nrSpectacolePromovateZilnic, bool deschisT, int oraDeschisT[7], int SpectacoleT) :idT(Teatru::contorT){
		this->tipTeatru = new char[strlen(tipTeatruT) + 1];
		strcpy(this->tipTeatru, tipTeatruT);
		this->adresaTeatru = adresaTeatruT;
		this->zile = zileT;
		this->Spectacole = SpectacoleT;
		if (this->nrSpectacolePromovate != NULL){
			delete[] this->nrSpectacolePromovate;
		}
		this->nrSpectacolePromovateZilnic = new float[this->zile];
		for (int i = 0; i < this->zile; i++){
			this->nrSpectacolePromovateZilnic[i] = nrSpectacolePromovateT[i];
		}
		this->deschis = deschisT;
		for (int i = 0; i < 7; i++){
			this->oraDeschis[i] = oraDeschisT[i];
		}

		Teatru::contorT++;
	}

	Teatru(float* nrSpectacolePromovateZilnicT, int zileT) :idT(Teatru::contorT){
		this->tipTeatru = new char[strlen("implicit") + 1];
		strcpy(this->tipTeatru, "implicit");
		this->zile = zileT;
		this->nrSpectacolePromovate = new float[this->zile];
		for (int i = 0; i < this->zile; i++) {
			this->nrSpectacolePromovateZilnic[i] = nrSpectacolePromovateZilnicT[i];
		}
		this->deschis = true;
		for (int i = 0; i < 7; i++){
			if (i < 5)
				this->oraDeschis[i] = 8;
			else
				this->oraDeschis[i] = 10;
		}
		Teatru::contorT++;
	}

	Teatru(Teatru& t) :idT(Teatru::contorT++){
		this->tipTeatru = new char[strlen(t.tipTeatru) + 1];
		this->adresaTeatru = t.adresaTeatru;
		strcpy(this->tipTeatru, t.tipTeatru);
		if (t.nrSpectacolePromovateZilnic != NULL){
			this->nrSpectacolePromovateZilnic = new float[t.zile];
			for (int i = 0; i < t.zile; i++){
				this->nrSpectacolePromovateZilnic[i] = t.nrSpectacolePromovateZilnic[i];
			}
			this->zile = t.zile;
			this->Spectacole = t.Spectacole;
		}
		else{
			this->nrSpectacolePromovateZilnic = NULL;
			this->zile = 0;
		}
		this->deschis = t.deschis;
		for (int i = 0; i < 7; i++){
			this->oraDeschis[i] = t.oraDeschis[i];
		}

		Teatru::contorT++;

	}

	#pragma endregion Constructori

	#pragma region Getteri si setteri 

	char* gettipTeatru(){
		return this->tipTeatru;
	}

	string getadresaTeatru(){
		return this->adresaTeatru;
	}

	float* getnrSpectacolePromovateZilnic(){
		return this->nrSpectacolePromovateZilnic;
	}

	int getzile() {
		return this->zile;
	}
	int getSpectacole(){
		return this->Spectacole;
	}

	bool getdeschis(){
		return this->deschis;
	}

	int getoraDeschis(int i){
		return this->oraDeschis[i];
	}



	int getidT(){
		return idT;
	}

	static int getcontorT(){
		return Teatru::contorT;
	}

	void settipTeatru(char* t_tipTeatru){
		if (this->tipTeatru != NULL){
			delete[] this->tipTeatru;
		}
		this->tipTeatru = new char[strlen(t_tipTeatru) + 1];
		strcpy(this->tipTeatru, t_tipTeatru);
	}

	void setadresaTeatru(string t_adresaTeatru){
		this->adresaTeatru = t_adresaTeatru;
	}

	void setnrSpectacolePromovateZilnic(int t_zile, float* t_nrSpectacolePromovateZilnic){
		if (this->nrSpectacolePromovateZilnic != NULL) {
			delete[] this->nrSpectacolePromovateZilnic;
		}
		this->zile = t_zile;
		this->nrSpectacolePromovateZilnic = new float[this->zile];
		for (int i = 0; i < this->zile; i++) {
			this->nrSpectacolePromovateZilnic[i] = t_nrSpectacolePromovateZilnic[i];
		}
	}

	void setdeschis(bool t_deschis){
		this->deschis = t_deschis;
	}

	void setoraDeschis(int t_oraDeschs[7]){
		if ((t_oraDeschs[5] < 6) && (t_oraDeschs[6] == 0)) 
			for (int i = 0; i < 7; i++) {
				this->oraDeschis[i] = t_oraDeschs[i];
			}
	}
	void setSpectacole(int t_Spectacole){
		this->Spectacole = t_Spectacole;
	}

	static void setcontorT(int t_contorT){
		Teatru::contorT = t_contorT;
	}

	#pragma endregion Getteri si setteri
	#pragma region Afisare si supraincarcari
	
	void afisareTeatru(){
		cout << "id Teatru: " << this->idT << endl;

		cout << "tip Teatru: " << this->tipTeatru << endl;
		cout << "zile Teatru: " << this->zile << endl;
		if (this->nrSpectacolePromovateZilnic != NULL){
			for (int i = 0; i < this->zile; i++){
				cout << "numar spectacole promovate zilnic: " << this->nrSpectacolePromovateZilnic[i] << endl;
			}
		}
		cout << "Spectacole: " << this->Spectacole;
		cout << "Deschis: " << this->deschis;
	}

	void inchidereTeatru(){
		int inchidere;
		cout << "Doriti sa inchideti teatrul?(1-DA,0-NU)" << endl;
		cin >> inchidere;
		if (inchidere == 1) {
			this->deschis = 0;
			cout << "Teatru inchis" << endl;
		}
		else{
			cout << "Teatru deschis";
		}
	}

	void operator=(const Teatru& teatr) {
		this->tipTeatru = teatr.tipTeatru;
		if (this->nrSpectacolePromovateZilnic != NULL) delete[]this->nrSpectacolePromovateZilnic;
		if (teatr.nrSpectacolePromovateZilnic != NULL) {
			this->nrSpectacolePromovateZilnic = new float[this->zile];
			for (int i = 0; i < teatr.zile; i++) {
				this->nrSpectacolePromovateZilnic[i] = teatr.nrSpectacolePromovateZilnic[i];
			}
			this->zile = teatr.zile;
		}
		else{
			this->nrSpectacolePromovateZilnic = NULL;
			this->zile = 0;
		}
		this->deschis = teatr.deschis;
	}

	friend ostream& operator<< (ostream& out, Teatru& t){
		out << "IdTeatru" << t.idT << endl;
		out << "Contor Teatru" << t.contorT << endl;
		out << "Filiala Teatru" << t.tipTeatru << endl;
		out << "Zile" << t.zile << endl;
		out << "Numar Spectacole:\n";
		if (t.nrSpectacolePromovateZilnic != NULL){
			for (int i = 0; i < t.zile; i++){
				out << t.nrSpectacolePromovateZilnic[i] << "Spectacole " << endl;
			}
		}
		else
			out << "Nu exista spectacole" << endl;
		out << "Deschis:" << t.deschis << endl;
		out << "Spectacole " << t.Spectacole << endl;
		return out;
	}

	friend istream& operator>> (istream& in, Teatru& t){
		cout << "tip teatru" << endl;
		char buff1[100];
		in.getline(buff1, 100);
		t.settipTeatru(buff1);
		cout << "Zile" << endl;
		in >> t.zile;
		if (t.nrSpectacolePromovateZilnic != NULL){
			delete[] t.nrSpectacolePromovateZilnic;
		}
		t.nrSpectacolePromovateZilnic = new float[t.zile];
		for (int i = 0; i < t.zile; i++){
			cout << "spectacole promovate in ziua" << i << endl;
			in >> t.nrSpectacolePromovateZilnic[i];
		}
		cout << "Deschis" << endl;
		in >> t.deschis;
		cout << "Spectacole" << endl;
		in >> t.Spectacole;
		return in;
	}

	float& operator[] (int index){
		if (index<0 || index>this->zile){
			cout << "Index in afara limitelor";
			throw new exception("Exceptie");
		}
		else {
			return this->nrSpectacolePromovateZilnic[index];
		}
	}
	
	friend Teatru operator+ (int prelungire_promovare, Teatru t) {
		Teatru copie = t;
		copie.zile = copie.zile + prelungire_promovare;
		return copie;
	}

	friend Teatru operator- (int scadenta, Teatru t){
		Teatru copie = t;
		copie.zile = copie.zile - scadenta;
		return copie;
	}

	Teatru& operator++ (){
		float* nrSpectacolePromovate = new float[this->zile + 1];
		for (int i = 0; i < zile; i++) {
			nrSpectacolePromovate[i] = this->nrSpectacolePromovate[i];
		}
		nrSpectacolePromovate[this->zile] = 0;
		this->zile++;
		if (this->nrSpectacolePromovateZilnic != NULL) {
			delete[]this->nrSpectacolePromovateZilnic;
		}
		this->nrSpectacolePromovateZilnic = nrSpectacolePromovate;
		return *this;
	}

	Teatru& operator++ (int){
		Teatru copie = *this;
		float* nrSpectacolePromovateZilnic = new float[this->zile + 1];
		for (int i = 0; i < zile; i++) {
			nrSpectacolePromovateZilnic[i] = this->nrSpectacolePromovateZilnic[i];
		}
		nrSpectacolePromovateZilnic[this->zile] = 0;
		this->zile++;
		if (this->nrSpectacolePromovateZilnic != NULL){
			delete[]this->nrSpectacolePromovateZilnic;
		}
		this->nrSpectacolePromovateZilnic = nrSpectacolePromovateZilnic;
		return copie;
	}

	explicit operator char* (){
		return this->tipTeatru;
	}
	
	bool operator! (){
		if (this->nrSpectacolePromovateZilnic != NULL){
			return false;
		}
		else return true;
		}

	bool operator==(Teatru t){
		if (this->tipTeatru == t.tipTeatru && this->zile == t.zile && this->nrSpectacolePromovateZilnic == t.nrSpectacolePromovateZilnic)
			return true;
		else
			return false;

	}

	bool operator>=(Teatru t){
		if (this->nrSpectacolePromovateZilnic >= t.nrSpectacolePromovateZilnic)
			return true;
		else return false;
	}

	~Teatru() 
	{
		if (this->tipTeatru != NULL) {
			delete[] this->tipTeatru;
		}
		if (this->nrSpectacolePromovateZilnic != NULL) {
			delete[] this->nrSpectacolePromovateZilnic;
		}
		cout << "Destructorul functioneaza";
	}
#pragma endregion Afisare si supraincarcari

	virtual void totalSpectacole() {
		int total = 0;
		cout << endl << "------------";
		cout << endl << "Numarul spectacolelor promovate in ultimele 7 zile este:";
		for (int i = 0; i < 7; i++) {
			total = total + this->nrSpectacolePromovateZilnic[i];
		}
		cout << total << endl;
	}

#pragma region Scriere si citire din fisier

	friend ofstream& operator<<(ofstream& out, Teatru t6){
		out << t6.idT << endl;
		out << t6.contorT << endl;
		out << t6.tipTeatru << endl;
		out << t6.adresaTeatru << endl;
		out << t6.zile << endl;
		for (int i = 0; i < t6.zile; i++){
			out << "\t" << t6.nrSpectacolePromovateZilnic[i] << " ";
		}
		out << t6.deschis << endl;
		out << t6.Spectacole << endl;
		for (int i = 0; i < 7; i++)
			out << "\t" << t6.oraDeschis[i] << " ";
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Teatru& t){
		char buff[50];
		in >> buff;
		t.settipTeatru(buff);
		in >> t.adresaTeatru;
		in >> t.deschis;
		if (t.deschis == false){
			in >> t.zile;
			in.ignore();
			if (t.nrSpectacolePromovateZilnic != NULL)
				delete[] t.nrSpectacolePromovateZilnic;
			t.nrSpectacolePromovateZilnic = new float[t.zile];
			for (int i = 0; i < t.zile; i++) {
				in >> t.nrSpectacolePromovateZilnic[i];
			}
		}
		else{
			t.zile = 0;
			t.nrSpectacolePromovateZilnic = NULL;
		}
		in >> t.Spectacole;
		for (int i = 0; i < 7; i++)
			in >> t.oraDeschis[i];
		return in;
	}
#pragma endregion Scriere si citire din fisier
};

int Teatru::contorT = 1;

class IInventarSector{
public:
	virtual void calculSpectacolePromovate(int perioada) = 0;
	virtual void calculSpectacoleRealizate(int perioada) = 0;
};

class Sector :public Teatru, public IInventarSector{
protected:
	string denumire;
	int nrSali;
public:
	Sector() : Teatru(){
		cout << "Constructor fara parametrii clasa Sector" << endl;
		this->denumire = "Teatru de revista";
		this->nrSali = 5;
	}
	string getdenumire(){
		return this->denumire;
	}

	int getnrSali(){
		return this->nrSali;
	}

	void setdenumire(string denumireN){
		this->denumire = denumireN;
	}

	void setnrSali(int nrSaliN){
		this->nrSali = nrSaliN;
	}

	virtual void totalSpectacole() override{
		int total = 0;
		cout << endl << "------------";
		cout << endl << "Numarul spectacolelor promovate in decursul ultimelor 7 zile este:";
		for (int i = 0; i < 7; i++) {
			total = total + this->nrSpectacolePromovate[i];
		}
		cout << total << endl;
	}

	virtual void Teatru_revista() = 0;
	virtual ~Sector(){
		cout << "Destructor sector" << endl;
	}

	void calculSpectacolePromovate(int perioada){
		int total = 0;
		if (perioada > this->zile) {
			cout << "Perioada invalida" << endl;
		}
		else {
			for (int i = 0; i < perioada; i++){
				total = total + this->nrSpectacolePromovateZilnic[i];
			}
			cout << "Spectacolele promovate in perioada de " << perioada << " zile: " << total << endl;
		}
	}
};

class Organizare :public Sector, public IInventarSector{
private:
	string mod_organizare;
public:
	Organizare() :Sector() {
		cout << "Constructor fara parametrii clasa Volum" << endl;
		this->mod_organizare = "Eveniment cu ocazia Craciunului";
	}
	

	string getmod_organizare(){
		return this->mod_organizare;
	}

	void setmod_organizare(string mod_organizareO){
		this->mod_organizare = mod_organizareO;
	}

	virtual void totalSpectacole() override{
		int total = 0;
		cout << endl << "------------";
		cout << endl << "Numarul spectacolelor promovate zilnic in decursul ultimelor 7 zile este:";
		for (int i = 0; i < 7; i++) {
			total = total + this->nrSpectacolePromovateZilnic[i];
		}
		cout << total << endl;
		cout << endl << "Acestea se aflau in sectorul " << this->denumire;
		cout << endl << "Spectacolele fac parte din " << this->mod_organizare;
	}

	void calculSpectacole(int perioada){
		if (perioada > this->zile){
			cout << "Perioada invalida" << endl;
		}
		else {
			cout << "Spectacolele realizare in perioada de " << perioada << " zile: " << Spectacole << endl;
		}
	}

};

int main(){
	#pragma region Teatru
	cout << "---------------------Teatru-----------------------" << endl;
	Teatru t1; 
	t1.afisareTeatru();
	char numetipTeatru2[21] = "Teatrul Nottara";
	float Spectacole2[3] = { 15, 2, 23 };
	int oraDeschidere2[7] = { 8,8,8,8,8,10,10 };
	float Spectacole[3] = { 10, 12, 13 };
	Teatru t2(Spectacole, 3); 
	t2.afisareTeatru();
	Teatru t3 = t2; 
	char numetipTeatru[20] = "Teatrul National";
	int oraDeschidere[7] = { 8,8,8,8,8,10,10 };
	t2.afisareTeatru();
	t1 = t2;
	t1.afisareTeatru();
	Teatru t4;
	cout << "Apel supraincarcare <<" << endl;
	cout << t4;
	cout << "Apel supraincarcare >>" << endl;
	cin >> t4;
	cout << t4;
	cout << "Apel supraincarcare +" << endl;
	t1 = 5 + t1;
	cout << t1.getzile() << endl;
	cout << "Apel supraincarcare -" << endl;
	t1 = 3 - t1;
	cout << t1.getzile() << endl;
	cout << "Apel supraincarcare indexare []";
	t4[2];
	cout << "Apelare operator ++(pre) " << endl;
	t4.getnrSpectacolePromovateZilnic();
	cout << (++t4).getnrSpectacolePromovateZilnic() << endl;
	cout << "Apelare operator ++ (post) " << endl;
	cout << (t4++).getnrSpectacolePromovateZilnic() << endl;
	cout << t4.getnrSpectacolePromovateZilnic() << endl;
	cout << "Tipul teatrului este " << (char*)t1 << endl;
	cout << "Apelare operator ! " << endl;
	if (!t3){
		cout << "Niciun spectacol promovat \n" << endl;
	}
	cout << "Apelare operator == " << endl;
	if (t3 == t4){
		cout << "Acelasi tip de teatru" << endl;
	}
	else
		cout << "Tipuri diferite" << endl;
		cout << "Apelare operator >= " << endl;
	if(t3 >= t4)
		cout << "Da" << endl;
	else
		cout << "Nu" << endl;
	try{
		cout << t1[4];
	}
	catch (exception* e){
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1" << endl;
	}
	catch (...){
		cout << "Exceptie prinsa 2" << endl;
	}
	char numeteatru[19] = "Teatrul Bulandra";
	float spectacolefisier[3] = {9, 15, 10};
	int ora[7] = { 8,8,8,8,8,10,10 };
	ofstream fileWrite;
	fileWrite.open("FisierTeatru.txt", ios::out);
	ifstream fileRead;
	fileRead.open("FisierTeatru.txt", ios::in);
	Teatru t7;
	fileRead >> t7;
	cout << "Obiect citit din fisier text: " << endl << t7;
	fileRead.close();
	ifstream fileReadBin;
	fileReadBin.open("FisierTeatru_binar.dat", ios::binary | ios::in);
	Teatru t8;
	fileReadBin >> t8;
	cout << "Obiect citit din fisier binar: " << endl << t8;
	fileReadBin.close();
	return 0;
}