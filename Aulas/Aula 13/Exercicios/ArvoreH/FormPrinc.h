//---------------------------------------------------------------------------

#ifndef FormPrincH
#define FormPrincH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Button1;
	TLabel *Label1;
	TCheckBox *CheckBox1;
	TEdit *Edit1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	void DesenhaLinhaV(int pX0, int pY0, int pAltura);
	void DesenhaLinhaH(int pX0, int pY0, int pLargura);
	void DesenhaH(int pX, int pY, double pTam);
	void DesenhaArvoreH(int pX, int pY, double pTam);
public:		// User declarations
	int pcont;



	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
