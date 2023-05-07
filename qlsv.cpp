#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 1000

/*--------------khai báo các struct để lưu thông tin sinh viên--------------------*/
struct date
{
    int ngay, thang, nam;
};

struct SinhVien
{
    int id;
    char hoTen[50];
    char gioiTinh[10];
    char diaChi[50];
    date NgaySinh;
    int tuoi;
    char sdt[13];
    float diemMon1;
    float diemMon2;
    float diemMon3;
    float diemTrungBinh;
    char xepLoai[10];
    char maLop[30];
};
typedef SinhVien SV; // định nghĩa kiểu SinhVien là SV

/*---------------Khai báo nguyên mẫu hàm--------------------*/
void xoaXuongDong(char str[]);
void nhapSinhVien(SV &sv);
void inSinhVien(SV sv);
void tinhTuoi(SV &sv);
void tinhDiemTrungBinh(SV *sv);
void xepLoai(SV &sv);
void capNhatSinhVien(SV &sv);
void nhapDanhSachSinhVien(SV ArrSV[], int &soLuongSinhVien);
void xuatDanhSachSinhVien(SV ArrSV[], int soLuongSinhVien);
float tim_MaxDTB(SV ArrSV[], int soLuongSinhVien);
int tim_MinTuoi(SV ArrSV[], int soLuongSinhVien);
void xuatDanhSachSinhVienXepLoai(SV ArrSV[], int soLuongSinhVien, char xepLoai[30]);
void xuatDanhSachSinhVienTheoLop(SV ArrSV[], int soLuongSinhVien, char maLop[]);
int timSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien, char ten[]);
void xoaSinhVienTheoID(SV ArrSV[], int &soLuongSinhVien, int maXoaID);
void sapXepSinhVienTheoDTB(SV ArrSV[], int soLuongSinhVien);
void sapXepSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien);
void ghiDuLieuSVVaoFile(SV ArrSV[], int soLuongSinhVien);
void nhanPhim();

/*-----------------------Hàm main xử lí chính----------------------*/
int main()
{
    SV ArrSV[MAX];
    int soLuongSinhVien;
    int luaChonSV;
    do
    {
        system("cls");
        printf("\n------------------MENU SINH VIEN------------------");
        printf("\n(1). Nhap Danh Sach Sinh Vien");
        printf("\n(2). Xuat Danh Sach Sinh Vien");
        printf("\n(3). Tim Diem Trung Binh Lon Nhat");
        printf("\n(4). Tim Tuoi Nho Nhat");
        printf("\n(5). Xuat Danh Sach Sinh Vien Xep Loai Gioi");
        printf("\n(6). Xuat Danh Sach Sinh Vien Theo Lop");
        printf("\n(7). Tim Sinh Vien Theo Ten");
        printf("\n(8). Xoa Sinh Vien Theo ID");
        printf("\n(9). Sap Xep Sinh Vien Theo DTB");
        printf("\n(10). Sap Xep Sinh Vien Theo Ten");
        printf("\n(11). Ghi Du Lieu Sinh Vien Vao File");
        printf("\n(0). Thoat");
        printf("\n--------------------------------------------------");

        printf("\nNhap Lua Chon Cua Ban : ");
        scanf("%d", &luaChonSV);

        switch (luaChonSV)
        {
        case 0:
        {
            printf("\nBan Da Thoat Khoi Chuong Trinh !");
            exit(0);
            break;
        }
        case 1:
        {
            nhapDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 2:
        {
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 3:
        {
            printf("\nMax DTB = %.1f", tim_MaxDTB(ArrSV, soLuongSinhVien));
            break;
        }
        case 4:
        {
            printf("\nMin Tuoi = %d", tim_MinTuoi(ArrSV, soLuongSinhVien));
            break;
        }
        case 5:
        {
            char xepLoai[30];
            fflush(stdin);
            printf("\nNhap xep loai muon xuat ra man hinh : ");
            fgets(xepLoai, sizeof(xepLoai), stdin);
            xoaXuongDong(xepLoai);
            xuatDanhSachSinhVienXepLoai(ArrSV, soLuongSinhVien, xepLoai);
            break;
        }
        case 6:
        {
            char maLop[30];
            printf("\nNhap lop can xuat danh sach sinh vien : ");
            fflush(stdin);
            fgets(maLop, sizeof(maLop), stdin);
            xoaXuongDong(maLop);
            xuatDanhSachSinhVienTheoLop(ArrSV, soLuongSinhVien, maLop);
            break;
        }
        case 7:
        {
            char ten[50];
            printf("Nhap ten sinh vien muon tim : ");
            fflush(stdin);
            fgets(ten, sizeof(ten), stdin);
            xoaXuongDong(ten);
            if (timSinhVienTheoTen(ArrSV, soLuongSinhVien, ten))
            {
                printf("\nTim thay sinh vien");
            }
            else
            {
                printf("\nKhong tim thay sinh vien");
            }
            break;
        }
        case 8:
        {
            int maXoaID;
            printf("\nNhap vao id can xoa : ");
            scanf("%d", &maXoaID);
            xoaSinhVienTheoID(ArrSV, soLuongSinhVien, maXoaID);
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 9:
        {
            printf("\nSau khi sap xep theo DTB !\n");
            sapXepSinhVienTheoDTB(ArrSV, soLuongSinhVien);
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 10:
        {
            printf("\nSau khi sap xep theo ten !");
            sapXepSinhVienTheoTen(ArrSV, soLuongSinhVien);
            xuatDanhSachSinhVien(ArrSV, soLuongSinhVien);
            break;
        }
        case 11:
        {
            ghiDuLieuSVVaoFile(ArrSV, soLuongSinhVien);
            break;
            //printf("\nChuc nang dang duoc cap nhat !");
        }

        }
        printf("\n");
        nhanPhim();
    } while (luaChonSV != 0);
    return 0;
}

/*hàm dừng màn hình lại cho người dùng nhấn phím rồi tiếp tục chạy*/
void nhanPhim()
{
    printf("\nNhan phim bat ki de tiep tuc :");
    getch();
}

/*hàm xóa dấu Enter sau khi gnuowfi dùng nhập xong*/
void xoaXuongDong(char str[])
{
    size_t len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

/*hàm nhập 1 sinh viên*/
void nhapSinhVien(SV &sv)
{
    printf("\nNhap ID : ");
    scanf("%d", &sv.id);

    printf("\nNhap ten : ");
    fflush(stdin);
    fgets(sv.hoTen, sizeof(sv.hoTen), stdin);
    xoaXuongDong(sv.hoTen);

    printf("\nNhap gioi tinh : ");
    fflush(stdin);
    fgets(sv.gioiTinh, sizeof(sv.gioiTinh), stdin);
    xoaXuongDong(sv.gioiTinh);

    printf("\nNhap dia chi : ");
    fflush(stdin);
    fgets(sv.diaChi, sizeof(sv.diaChi), stdin);
    xoaXuongDong(sv.diaChi);

    printf("\nNhap ngay sinh : ");
    scanf("%d%d%d", &sv.NgaySinh.ngay, &sv.NgaySinh.thang, &sv.NgaySinh.nam);

    printf("\nNhap sdt : ");
    fflush(stdin);
    fgets(sv.sdt, sizeof(sv.sdt), stdin);
    xoaXuongDong(sv.sdt);

    printf("\nNhap diem mon 1 : ");
    scanf("%f", &sv.diemMon1);
    printf("\nNhap diem mon 2 : ");
    scanf("%f", &sv.diemMon2);
    printf("\nNhap diem mon 3 : ");
    scanf("%f", &sv.diemMon3);

    printf("\nNhap ma lop : ");
    fflush(stdin);
    fgets(sv.maLop, sizeof(sv.maLop), stdin);
    xoaXuongDong(sv.maLop);
}

/*hàm in thông tin 1 sinh viên */
void inSinhVien(SV sv)
{
    printf("\n%5d \t %10s \t %5s \t\t %10s \t %2d/%d/%d \t\t %5d \t\t %10s \t %.1f \t\t %.1f \t\t %.1f \t %.1f \t\t %5s \t\t %5s",
           sv.id, sv.hoTen, sv.gioiTinh, sv.diaChi, sv.NgaySinh.ngay, sv.NgaySinh.thang, sv.NgaySinh.nam, sv.tuoi, sv.sdt, sv.diemMon1, sv.diemMon2, sv.diemMon3, sv.diemTrungBinh, sv.xepLoai, sv.maLop);
}

/*hàm tính tuổi sinh viên sử dụng thư viện <time.h> đẻ lấy thời gian theo hệ thông*/
void tinhTuoi(SV &sv)
{
    time_t TIME = time(0);
    tm *NOW = localtime(&TIME);
    int namHienTai = NOW->tm_year + 1900;
    sv.tuoi = namHienTai - sv.NgaySinh.nam;
}

/*hàm có chức năng tính điểm trung bình của sinh viên */
void tinhDiemTrungBinh(SV *sv)
{
    sv->diemTrungBinh = (sv->diemMon1 + sv->diemMon2 + sv->diemMon3) / 3;
}

/*hàm xếp loại sinh viên theo điểm trung bình*/
void xepLoai(SV &sv)
{
    if (sv.diemTrungBinh > 8)
    {
        strcpy(sv.xepLoai, "GIOI");
    }
    else if (sv.diemTrungBinh > 7)
    {
        strcpy(sv.xepLoai, "KHA");
    }
    else if (sv.diemTrungBinh >= 5)
    {
        strcpy(sv.xepLoai, "TB");
    }
    else
    {
        strcpy(sv.xepLoai, "YEU");
    }
}


void capNhatSinhVien(SV &sv)
{
    nhapSinhVien(sv);
    tinhTuoi(sv);
    tinhDiemTrungBinh(&sv);
    xepLoai(sv);
}

/*hàm nhập danh sách snh viên luu vào 1 mảng*/
void nhapDanhSachSinhVien(SV ArrSV[], int &soLuongSinhVien)
{
    do
    {
        printf("Nhap so luong sinh vien : ");
        scanf("%d", &soLuongSinhVien);
    } while (soLuongSinhVien <= 0 || soLuongSinhVien > MAX);
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        printf("\n");
        printf("Nhap sinh vien thu [%d]\n", i);
        capNhatSinhVien(ArrSV[i]);
    }
}

/*hàm xuất danh sách sinh viên*/
void xuatDanhSachSinhVien(SV ArrSV[], int soLuongSinhVien)
{
    printf("\n%5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s", "ID", "Ten", "GT", "DC", "NS", "Tuoi", "SDT", "Diem 1", "Diem 2", "Diem 3", "DTB", "Xep Loai", "Lop");
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        inSinhVien(ArrSV[i]);
    }
}

/*hàm tìm ra điểm trung bình lớn nhất*/
float tim_MaxDTB(SV ArrSV[], int soLuongSinhVien)
{
    float maxDTB = ArrSV[0].diemTrungBinh;
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (ArrSV[i].diemTrungBinh > maxDTB)
        {
            maxDTB = ArrSV[i].diemTrungBinh;
        }
    }
    return maxDTB;
}

/*hàm tìm sinh viên có tuổi nhỏ nhất*/
int tim_MinTuoi(SV ArrSV[], int soLuongSinhVien)
{
    int minTuoi = ArrSV[0].tuoi;
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (ArrSV[i].tuoi < minTuoi)
        {
            minTuoi = ArrSV[i].tuoi;
        }
    }
    return minTuoi;
}

/*hàm xuất danh sachs sinh viên theo loại do người dùng nhập từ bên ngoài*/
void xuatDanhSachSinhVienXepLoai(SV ArrSV[], int soLuongSinhVien, char xepLoai[30])
{
    printf("\nDanh sach sinh vien xep loai gioi: \n");
    printf("%5s \t %10s \t %5s \t %10s \t %10s \t\t %5s \t\t %5s \t %5s \t %5s \t %5s \t %5s \t %5s \t %5s", "ID", "Ten", "Gioi Tinh", "Dia Chi", "Ngay Sinh", "Tuoi", "Sdt", "Diem 1", "Diem 2", "Diem 3", "DTB", "Xep Loai", "Lop");
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (strcmp(strupr(ArrSV[i].xepLoai), strupr(xepLoai)) == 0)
        {
            inSinhVien(ArrSV[i]);
        }
    }
}

/*hàm xuất dánh sách sinh viên theo lớp do gnuowfi dùng nhập*/
void xuatDanhSachSinhVienTheoLop(SV ArrSV[], int soLuongSinhVien, char maLop[])
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (strcmp(strupr(ArrSV[i].maLop), strupr(maLop)) == 0)
        {
            inSinhVien(ArrSV[i]);
        }
    }
}

/*hàm tìm sịnh viên theo tên*/
int timSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien, char ten[])
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (strstr(strupr(ArrSV[i].hoTen), strupr(ten)))
        {
            return 1;
            break;
        }
    }
    return 0;
}

/*hàm xóa sinh viên the id*/
void xoaSinhVienTheoID(SV ArrSV[], int &soLuongSinhVien, int maXoaID)
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        if (ArrSV[i].id == maXoaID)
        {
            for (int j = i; j < soLuongSinhVien; j++)
            {
                ArrSV[j] = ArrSV[j + 1];
            }
            soLuongSinhVien--;
        }
    }
}

/*hàm sắp xếp sinh viên theo điểm trung bình*/
void sapXepSinhVienTheoDTB(SV ArrSV[], int soLuongSinhVien)
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        for (int j = i + 1; j < soLuongSinhVien; j++)
        {
            if (ArrSV[i].diemTrungBinh < ArrSV[j].diemTrungBinh)
            {
                SV temp = ArrSV[i];
                ArrSV[i] = ArrSV[j];
                ArrSV[j] = temp;
            }
        }
    }
}

/*hàm sắp xếp sinh viên theo tên*/
void sapXepSinhVienTheoTen(SV ArrSV[], int soLuongSinhVien)
{
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        for (int j = i + 1; j < soLuongSinhVien; j++)
        {
            if (strcmp(ArrSV[i].hoTen, ArrSV[j].hoTen) > 0)
            {
                SV temp = ArrSV[i];
                ArrSV[i] = ArrSV[j];
                ArrSV[j] = temp;
            }
        }
    }
}

/*hàm có chức năng ghi thông tin vào file*/
void ghiDuLieuSVVaoFile(SV ArrSV[], int soLuongSinhVien)
{
    // khai báo biến con trỏ làm việc với file
    FILE *fptr;

    // tạo hoặc mở file 
    fptr = fopen("sinhvien.txt", "w");

    // kiểm tra con trỏ nếu giá trị null thì không thể tạo thêm file
    if (fptr == NULL)
    {
        printf("Error !");
        exit(0);
    }

    // đọc số lượng sinh viên vào file
    fprintf(fptr, "So luong sinh vien la : ");
    fprintf(fptr, "%d", soLuongSinhVien);

    // đọc danh sách sinh viên vào file
    fprintf(fptr,"\n%5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s \t\t %5s", "ID", "Ten", "GT", "DC", "NS", "Tuoi", "SDT", "Diem 1", "Diem 2", "Diem 3", "DTB", "Xep Loai", "Lop");
    for (int i = 0; i < soLuongSinhVien; i++)
    {
        fprintf(fptr, "\n%5d \t %10s \t %5s \t\t %10s \t %2d/%d/%d \t\t %5d \t\t %10s \t %.1f \t\t %.1f \t\t %.1f \t %.1f \t\t %5s \t\t %5s",
                ArrSV[i].id, ArrSV[i].hoTen, ArrSV[i].gioiTinh, ArrSV[i].diaChi, ArrSV[i].NgaySinh.ngay, ArrSV[i].NgaySinh.thang, ArrSV[i].NgaySinh.nam, ArrSV[i].tuoi, ArrSV[i].sdt, ArrSV[i].diemMon1, ArrSV[i].diemMon2, ArrSV[i].diemMon3, ArrSV[i].diemTrungBinh, ArrSV[i].xepLoai, ArrSV[i].maLop);
    }

    // đóng file
    fclose(fptr);
}
