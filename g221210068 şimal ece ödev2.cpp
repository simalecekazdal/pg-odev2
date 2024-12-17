/************************************************************************
**					          SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…............: 2
**				ÖĞRENCİ ADI...............: ŞİMAL ECE KAZDAL
**				ÖĞRENCİ NUMARASI..........: G221210068
**				DERS GRUBU................: 2A
************************************************************************/


#include <iostream>
#include <math.h>
#include <cmath>
#include <locale.h>

//kullanılacak kütüphaneleri ekledim

using namespace std;

class karmasikSayilar

	//karmaşık sayı sınıfı oluşturdum

{

public:
	void girdi()

		//girlecek değerler için fonksiyon yazdım

	{
		cout << " Sayinin gercel kismini giriniz: ";
		cin >> gercel;
		cout << " Sayinin sanal kismini giriniz : ";
		cin >> sanal;
	}
	void cikti()

		//ekrana yazılacak değer için çıktı fonksiyonunu yazdım

	{
		if (sanal < 0)

			//girilen sanal kısım negatif ise ekrana yazdırılması gereken değeri girdim.

		{
			cout << " Sayi = " << gercel << " " << sanal << "i" << endl;
		}
		else

			//girilen sanal kısım 0'dan küçük değil ise yazdırılması gereken değeri tanımladım.

		{
			cout << " Sayi = " << gercel << "+" << sanal << "i" << endl;
		}
	}
	karmasikSayilar operator+ (karmasikSayilar islem)

		//toplama işlemini sisteme tanımladım.

	{
		karmasikSayilar sonuc;
		sonuc.gercel = gercel + islem.gercel;
		sonuc.sanal = sanal + islem.sanal;
		return sonuc;
	}
	karmasikSayilar operator- (karmasikSayilar islem)

		//çıkarma işlemini sisteme tanımladım.

	{
		karmasikSayilar sonuc;
		sonuc.gercel = gercel - islem.gercel;
		sonuc.sanal = sanal - islem.sanal;
		return sonuc;
	}
	karmasikSayilar operator* (karmasikSayilar islem)

		//çarpma işlemini sisteme tanımladım.

	{
		karmasikSayilar sonuc;
		sonuc.gercel = gercel * islem.gercel - sanal * islem.sanal;
		sonuc.sanal = gercel * islem.sanal + sanal * islem.gercel;
		return sonuc;
	}
	karmasikSayilar operator/ (karmasikSayilar islem)

		//bölme işlemini sisteme tanımladım.

	{
		karmasikSayilar sonuc;
		float gercelsayi = islem.gercel * islem.gercel + islem.sanal * islem.sanal;
		sonuc.gercel = (gercel * islem.gercel - sanal * (-1 * islem.sanal)) / gercelsayi;
		sonuc.sanal = (gercel * (-1 * islem.sanal) + sanal * islem.gercel) / gercelsayi;
		return sonuc;
	}
	karmasikSayilar operator+= (karmasikSayilar islem)

		//toplam atama işlemini sisteme tanımladım.

	{
		karmasikSayilar sonuc;
		gercel = gercel + islem.gercel;
		sanal = sanal + islem.sanal;
		return *this;
	}
	karmasikSayilar operator-= (karmasikSayilar islem)

		// fark atama işlemini sisteme tanımladım.

	{
		karmasikSayilar sonuc;
		gercel = gercel - islem.gercel;
		sanal = sanal - islem.sanal;
		return *this;
	}
	karmasikSayilar operator*= (karmasikSayilar islem)

		//çarpım atama işlemini sisteme tanımladım.

	{
		karmasikSayilar sonuc;
		gercel = islem.gercel - sanal * islem.sanal;
		sanal = islem.sanal + sanal * islem.gercel;
		return *this;
	}
	karmasikSayilar operator/= (karmasikSayilar islem)

		//bölüm atama işlemini sisteme tanımmladım.

	{
		karmasikSayilar sonuc;
		float gercelsayi = islem.gercel * islem.gercel + islem.sanal * islem.sanal;
		gercel = (gercel * islem.gercel - sanal * ((-1) * islem.sanal)) / gercelsayi;
		sanal = (gercel * ((-1) * islem.sanal) + sanal * islem.gercel) / gercelsayi;
		return *this;
	}

	void kutupsalGosterim()

		// kutupsal gösterim için işlemi tanımladım.

	{
		double y;
		double aciDegeri;
		double tanjant = i / r;
		const double derece = 180 / 3.141593;
		y = sqrt((r * r) + (i * i));
		aciDegeri = atan(tanjant) * derece;

		if (r >= 0 && i > 0)
		{
			cout << " r   : " << y << endl;
			cout << " aci : " << aciDegeri << endl;
		}
		else if (r >= 0 && i < 0)
		{
			cout << " r   : " << y << endl;
			cout << " aci : " << 360 + aciDegeri << endl;
		}
		else if (r <= 0 && i > 0)
		{
			cout << " r   : " << y << endl;
			cout << " aci : " << 180 + aciDegeri << endl;
		}
		else if (r <= 0 && i < 0)
		{
			cout << " r   : " << y << endl;
			cout << " aci : " << 180 + aciDegeri << endl;
		}
	}

private:

	// kodumda kullandığım verileri sınıfın içinde sisteme tanımladım.

	float gercel;
	float sanal;
	float i;
	float r;
};

int main()
{
	setlocale(LC_ALL, "Turkish");

	// türkçe karakter kullanımı için girdim.

	system("color 73");
	// çıktı ekranının renkli olmasını istediğim için kullandım.

	karmasikSayilar karmasikSayi;
	karmasikSayi.girdi();
	karmasikSayi.cikti();
	karmasikSayilar karmasikSayi2;
	cout << endl;
	karmasikSayi2.girdi();
	karmasikSayi2.cikti();

	karmasikSayilar toplama, cikartma, carpma, bolme;

	// işlemleri isimleri ile tanımladım

	toplama = karmasikSayi + karmasikSayi2;
	cikartma = karmasikSayi - karmasikSayi2;
	carpma = karmasikSayi * karmasikSayi2;
	bolme = karmasikSayi / karmasikSayi2;

	char menusecim;

	do

		// açtığım döngü ile menü ekleyip seçim yapılmasını sağladım.

	{
		cout << endl;
		cout << "-----------------------MENU SECIM----------------------- \n";
		cout << " Yapmak istediginiz islemi seciniz         : \n";
		cout << " Toplama islemi icin                       1'e \n";
		cout << " Cikartma islemi icin                      2'ye \n";
		cout << " Carpma islemi icin                        3'e \n";
		cout << " Bolme islemi icin                         4'e \n";
		cout << " += islemi icin                            5'e \n";
		cout << " -= islemi icin                            6'ya \n";
		cout << " *= islemi icin                            7'ye \n";
		cout << " /= islemi icin                            8'e \n";
		cout << " Kutupsal gosterim icin                    9'a basiniz. \n";
		cout << "-------------------------------------------------------- \n" << endl;
		cout << " Secilen islem : ";
		cin >> menusecim;
	} while (!(menusecim == '1' || menusecim == '2' || menusecim == '3' || menusecim == '4' || menusecim == '5' || menusecim == '6' || menusecim == '7' || menusecim == '8' || menusecim == '9'));
	switch (menusecim)
	{

		//case ler ile klavyeden hangi değer girilirse ekranda ne çıkması gerektiğini tanımladım.

	case '1':
		cout << endl << " Toplam :\n ";
		toplama.cikti();
		break;
	case '2':
		cout << endl << " Fark   :\n ";
		cikartma.cikti();
		break;
	case '3':
		cout << endl << " Carpim :\n ";
		carpma.cikti();
		break;
	case '4':
		cout << endl << " Bolum  :\n ";
		bolme.cikti();
		break;
	case '5':
		karmasikSayi = toplama;
		cout << endl << " += Sonucu :\n ";
		toplama.cikti();
		break;
	case '6':
		karmasikSayi = cikartma;
		cout << endl << " -= Sonucu :\n ";
		cikartma.cikti();
		break;
	case '7':
		karmasikSayi = carpma;
		cout << endl << " *= Sonucu :\n ";
		carpma.cikti();
		break;
	case '8':
		karmasikSayi = bolme;
		cout << endl << " /= Sonucu :\n ";
		bolme.cikti();
		break;
	case '9':
		cout << endl << " - Kutupsal Gosterim - \n";
		karmasikSayi.kutupsalGosterim();
		break;
	default:
		cout << " Hatali secenek girdiniz lutfen 1 ve 9 arasinda bir deger giriniz \n";
		break;
	}
	return 0;
}