//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "FormPrinc.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::DesenhaLinhaV(int pX0, int pY0, int pAltura)
{
  TLine *plinha;

  plinha = new TLine(this->GroupBox1);
  plinha->LineType = 2; //ltLeft; //Linha vertical � esquerda
  plinha->Position->X = pX0;
  plinha->Position->Y = pY0;
  plinha->Width  = 5;
  plinha->Height = pAltura;
  plinha->Visible = true;
  this->GroupBox1->AddObject(plinha);
}
//---------------------------------------------------------------------------
void TForm1::DesenhaLinhaH(int pX0, int pY0, int pLargura)
{
  TLine *plinha;

  plinha = new TLine(this->GroupBox1);
  plinha->LineType = 1; //ltTop; //Linha horizontal acima
  plinha->Position->X = pX0;
  plinha->Position->Y = pY0;
  plinha->Width  = pLargura;
  plinha->Height = 5;
  plinha->Visible = true;
  this->GroupBox1->AddObject(plinha);
}

//---------------------------------------------------------------------------
void TForm1::DesenhaH(int pX, int pY, double pTam)
{
  double px0 = pX - pTam/2;
  double px1 = pX + pTam/2;
  double py0 = pY - pTam/2;
  double py1 = pY + pTam/2;

  DesenhaLinhaV(px0, py0, pTam);
  DesenhaLinhaV(px1, py0, pTam);
  DesenhaLinhaH(px0, py0+pTam/2, pTam);
  this->GroupBox1->Repaint();
}

//---------------------------------------------------------------------------
void TForm1::DesenhaArvoreH(int pX, int pY, double pTam)
{
  double pMx = pTam/2, pMy = pTam/2;
  int presp;
  if(pTam>=1)
  {
	 if(!CheckBox1->IsChecked)
	 {
	   DesenhaH(pX,pY, pTam);
	   DesenhaArvoreH(pX-pMx,pY-pMy, pTam/2);   //Canto esquerdo superior
	   DesenhaArvoreH(pX-pMx,pY+pMy, pTam/2);   //Canto esquerdo inferior
	   DesenhaArvoreH(pX+pMx,pY-pMy, pTam/2);   //Canto direito superior
	   DesenhaArvoreH(pX+pMx,pY+pMy, pTam/2);   //Canto direito inferior
	   Application->ProcessMessages();
	 }
	 else
	   this->Button1->Enabled = false;
/*	 DesenhaArvoreH(pX-pMx,pY-pMy, pTam/2);   //Canto esquerdo superior
	 DesenhaArvoreH(pX-pMx,pY+pMy, pTam/2);   //Canto esquerdo inferior
	 DesenhaArvoreH(pX+pMx,pY-pMy, pTam/2);   //Canto direito superior
	 DesenhaArvoreH(pX+pMx,pY+pMy, pTam/2);   //Canto direito inferior
*/
  }

}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  int pcentroX, pcentroY, pl;
  pcentroX = GroupBox1->Width/2;
  pcentroY = GroupBox1->Height/2;
  DesenhaArvoreH(pcentroX, pcentroY, Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------

