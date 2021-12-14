#include <iostream>
#include <unistd.h> //Header for using sleep().

using namespace std;

int retryOrNot(), buatMatrik(), inputNilaiMatrik(), transposeMatrik();
void checkOs(), endOfLife();
int matrik[10][10], transposedMatrik[10][10];
int baris, kolom, chances = 3, flag = 0;
string retryOrNo;

int main() {
  flag++;
  checkOs();
  (flag > 1) ? puts("Selamat datang kembali diprogram tranpose matrik, silakan ikuti arahan.") : puts("Selamat datang diprogram tranpose matrik, silakan ikuti arahan.");
  buatMatrik();
  return 0;
}

int retryOrNot(string data, string namePasser) {
  if(namePasser == "buatMatrik") {
    if(data == "N" || data == "n") {
    checkOs();
    buatMatrik();
    }
    else if(data == "Y" || data == "y") {
      checkOs();
      inputNilaiMatrik();
    } else {
      if(chances == 1) {
        endOfLife();
        return 0;
      }
      printf("Input tidak terdaftar, silahkan ulangi: ");
      cin>>retryOrNo;
      chances--;
      retryOrNot(retryOrNo, "buatMatrik");
    }
  }
  else if(namePasser ==  "inputNilaiMatrik") {
    if(data == "N" || data == "n") {
      checkOs();
      inputNilaiMatrik();
    }
    else if(data == "Y" || data == "y") {
      checkOs();
      transposeMatrik();
    } else {
      if(chances == 0) {
        endOfLife();
        return 0;
      }
      printf("Input tidak terdaftar, silahkan ulangi: ");
      cin>>retryOrNo;
      chances--;
      retryOrNot(retryOrNo, "buatMatrik");
    }
  }
  else if(namePasser == "transposeMatrik") {
    if(data == "N" || data == "n") {
      puts("Terimakasih telah menggunakan program transpose matrik, sampai jumpa!<3");
      sleep(2.5);
      checkOs();
      return 0;
    }
    else if(data == "Y" || data == "y") {
      checkOs();
      main();
    } else {
      if(chances == 0) {
        endOfLife();
        return 0;
      }
      printf("Input tidak terdaftar, silahkan ulangi: ");
      cin>>retryOrNo;
      chances--;
      retryOrNot(retryOrNo, "buatMatrik");
    }
  }
  return 0;
}

int buatMatrik() {
  int numberOfArrayIndex  = 1;
  puts("Silahkan masukkan dimensi matrik");
  cout<<"Baris Matrik: ";
  cin>>baris;
  cout<<"Kolom Matrik: ";
  cin>>kolom;
  printf("Dimensi matrik anda adalah %d x %d, dengan ilustrasi seperti dibawah :\n", baris, kolom);
  cout<<endl;
  for(int i = 0; i < baris; i++) {
    for(int j = 0; j < kolom; j++) {
      printf("[%d]\t", numberOfArrayIndex);
      numberOfArrayIndex++;
      if(j == (kolom - 1)) {
        cout<<endl;
      }
    }
  }
  cout<<endl;
  cout<<"Apakah sudah benar? Silakan input Y/y jika benar, N/n jika salah: ";
  cin>>retryOrNo;
  retryOrNot(retryOrNo, "buatMatrik");
  return 0;
}

int inputNilaiMatrik() {
  puts("Slahkan masukkan nilai matrik sesuai baris & kolomnya:");
  puts("\t\t========");
  for(int i = 0; i < baris; i++) {
    for(int j = 0; j < kolom; j++) {
      printf("Masukkan nilai matrik kolom ke-%d, baris ke-%d: ", (j + 1), (i + 1));
      cin>>matrik[i][j];
    }
  }
  puts("Preview: ");
  for(int i = 0; i < baris; i++) {
    for(int j = 0; j < kolom; j++) {
      cout<<"["<<matrik[i][j]<<"]"<<"\t";
      if(j == (kolom - 1)) {
        cout<<endl;
      }
    }
  }
  cout<<"Apakah sudah benar? Silakan input Y/y jika benar, N/n jika salah: ";
  cin>>retryOrNo;
  retryOrNot(retryOrNo, "inputNilaiMatrik");
  return 0;
}

int transposeMatrik() {
  checkOs();
  cout<<endl;
  for(int i = 0; i < baris; i++) {
    for(int j = 0; j < kolom; j++) {
      cout<<"["<<matrik[i][j]<<"["<<"\t";
      if(j == (kolom - 1)) {
        cout<<endl;
      }
    }
  }
  puts("\n\t\t=Mentranspose Matrik=");
  for(int i = 0; i < baris; i++) {
    for(int j = 0; j < kolom; j++) {
      transposedMatrik[j][i] = matrik[i][j];
    }
  }
  cout<<endl;
  for(int i = 0; i < kolom; i++) {
    for(int j = 0; j < baris; j++) {
      cout<<"["<<transposedMatrik[i][j]<<"]"<<"\t";
      if(j == (kolom - 1)) {
        cout<<endl;
      }
    }
  }
  cout<<"\nUlangi program? Silakan input Y/y jika ingin mengulang, N/n jika tidak: ";
  cin>>retryOrNo;
  retryOrNot(retryOrNo, "transposeMatrik");
  return 0;
}

void checkOs() {
  #if OS_Windows
    system("cls");
  #else
    system("clear");
  #endif
}

void endOfLife() {
  puts("Input telah salah sebanyak 3x, program dihentikan!");
  sleep(1.5);
  checkOs();
}