// Mainframe macro generated from application: /home/alek/Programy/root-system//bin/root.exe
// By ROOT version 5.34/26 on 2018-01-15 15:59:15

#if !defined( __CINT__) || defined (__MAKECINT__)

#ifndef ROOT_TStyle
#include "TStyle.h"
#endif

#endif

void thesisStyle()
{
   // Add the saved style to the current ROOT session.

   delete gROOT->GetStyle("thesis");

   TStyle *tmpStyle = new TStyle("thesis", "thesis");

   tmpStyle->SetLineColor(1);
   tmpStyle->SetLineStyle(1);
   tmpStyle->SetLineWidth(1);
   tmpStyle->SetFillColor(600);
   tmpStyle->SetFillStyle(3002);
   tmpStyle->SetMarkerColor(1);
   tmpStyle->SetMarkerSize(1);
   tmpStyle->SetMarkerStyle(1);
   tmpStyle->SetTextAlign(11);
   tmpStyle->SetTextAngle(0);
   tmpStyle->SetTextColor(1);
   tmpStyle->SetTextFont(132);
   tmpStyle->SetTextSize(0.05);

   tmpStyle->SetNdivisions(510, "x");
   tmpStyle->SetNdivisions(510, "y");
   tmpStyle->SetNdivisions(510, "z");
   tmpStyle->SetAxisColor(1, "x");
   tmpStyle->SetAxisColor(1, "y");
   tmpStyle->SetAxisColor(1, "z");
   tmpStyle->SetLabelColor(1, "x");
   tmpStyle->SetLabelColor(1, "y");
   tmpStyle->SetLabelColor(1, "z");
   tmpStyle->SetLabelFont(132, "x");
   tmpStyle->SetLabelFont(132, "y");
   tmpStyle->SetLabelFont(132, "z");
   tmpStyle->SetLabelOffset(0.015, "x");
   tmpStyle->SetLabelOffset(0.015, "y");
   tmpStyle->SetLabelOffset(0.015, "z");
   tmpStyle->SetLabelSize(0.045, "x");
   tmpStyle->SetLabelSize(0.045, "y");
   tmpStyle->SetLabelSize(0.045, "z");
   tmpStyle->SetTickLength(0.02, "x");
   tmpStyle->SetTickLength(0.02, "y");
   tmpStyle->SetTickLength(0.02, "z");
   tmpStyle->SetTitleOffset(1.15, "x");
   tmpStyle->SetTitleOffset(1.5, "y");
   tmpStyle->SetTitleOffset(1, "z");
   tmpStyle->SetTitleSize(0.05, "x");
   tmpStyle->SetTitleSize(0.05, "y");
   tmpStyle->SetTitleSize(0.05, "z");
   tmpStyle->SetTitleColor(1, "x");
   tmpStyle->SetTitleColor(1, "y");
   tmpStyle->SetTitleColor(1, "z");
   tmpStyle->SetTitleFont(132, "x");
   tmpStyle->SetTitleFont(132, "y");
   tmpStyle->SetTitleFont(132, "z");
   tmpStyle->SetBarWidth(1);
   tmpStyle->SetBarOffset(0);
   tmpStyle->SetDrawBorder(0);
   tmpStyle->SetOptLogx(0);
   tmpStyle->SetOptLogy(0);
   tmpStyle->SetOptLogz(0);
   tmpStyle->SetOptDate(0);
   tmpStyle->SetOptStat(1110);
   tmpStyle->SetOptTitle(kTRUE);
   tmpStyle->SetOptFit(111);
   tmpStyle->SetNumberContours(20);
   tmpStyle->GetAttDate()->SetTextFont(132);
   tmpStyle->GetAttDate()->SetTextSize(0.025);
   tmpStyle->GetAttDate()->SetTextAngle(0);
   tmpStyle->GetAttDate()->SetTextAlign(11);
   tmpStyle->GetAttDate()->SetTextColor(1);
   tmpStyle->SetDateX(0.01);
   tmpStyle->SetDateY(0.01);
   tmpStyle->SetEndErrorSize(2);
   tmpStyle->SetErrorX(0.5);
   tmpStyle->SetFuncColor(1);
   tmpStyle->SetFuncStyle(1);
   tmpStyle->SetFuncWidth(2);
   tmpStyle->SetGridColor(0);
   tmpStyle->SetGridStyle(3);
   tmpStyle->SetGridWidth(1);
   tmpStyle->SetLegendBorderSize(-1);
   tmpStyle->SetLegendFillColor(0);
   tmpStyle->SetLegendFont(132);
   tmpStyle->SetHatchesLineWidth(1);
   tmpStyle->SetHatchesSpacing(1);
   tmpStyle->SetFrameFillColor(0);
   tmpStyle->SetFrameLineColor(1);
   tmpStyle->SetFrameFillStyle(0);
   tmpStyle->SetFrameLineStyle(0);
   tmpStyle->SetFrameLineWidth(1);
   tmpStyle->SetFrameBorderSize(0);
   tmpStyle->SetFrameBorderMode(0);
   tmpStyle->SetHistFillColor(600);
   tmpStyle->SetHistLineColor(kBlue);
   tmpStyle->SetHistFillStyle(3002);
   tmpStyle->SetHistLineStyle(1);
   tmpStyle->SetHistLineWidth(2);
   tmpStyle->SetHistMinimumZero(kTRUE);
   tmpStyle->SetCanvasPreferGL(kFALSE);
   tmpStyle->SetCanvasColor(0);
   tmpStyle->SetCanvasBorderSize(0);
   tmpStyle->SetCanvasBorderMode(0);
   tmpStyle->SetCanvasDefH(550);
   tmpStyle->SetCanvasDefW(600);
   tmpStyle->SetCanvasDefX(10);
   tmpStyle->SetCanvasDefY(10);
   tmpStyle->SetPadColor(19);
   tmpStyle->SetPadBorderSize(1);
   tmpStyle->SetPadBorderMode(0);
   tmpStyle->SetPadBottomMargin(0.13);
   tmpStyle->SetPadTopMargin(0.08);
   tmpStyle->SetPadLeftMargin(0.16);
   tmpStyle->SetPadRightMargin(0.03);
   tmpStyle->SetPadGridX(kFALSE);
   tmpStyle->SetPadGridY(kFALSE);
   tmpStyle->SetPadTickX(1);
   tmpStyle->SetPadTickY(1);
   tmpStyle->SetPaperSize(20, 26);
   tmpStyle->SetScreenFactor(1);
   tmpStyle->SetStatColor(19);
   tmpStyle->SetStatTextColor(1);
   tmpStyle->SetStatBorderSize(-1);
   tmpStyle->SetStatFont(132);
   tmpStyle->SetStatFontSize(0);
   tmpStyle->SetStatStyle(0);
   tmpStyle->SetStatFormat("6.4f");
   tmpStyle->SetStatX(0.95);
   tmpStyle->SetStatY(0.9);
   tmpStyle->SetStatW(0.25);
   tmpStyle->SetStatH(0.125);
   tmpStyle->SetStripDecimals(kFALSE);
   tmpStyle->SetTitleAlign(13);
   tmpStyle->SetTitleFillColor(19);
   tmpStyle->SetTitleTextColor(1);
   tmpStyle->SetTitleBorderSize(0);
   tmpStyle->SetTitleFont(132, "");
   tmpStyle->SetTitleFontSize(0.05);
   tmpStyle->SetTitleStyle(0);
   tmpStyle->SetTitleX(0.12);
   tmpStyle->SetTitleY(0.995);
   tmpStyle->SetTitleW(0.78);
   tmpStyle->SetTitleH(0);
   tmpStyle->SetLegoInnerR(0.5);

   Int_t fPaletteColor[50] = {51, 52, 53, 54, 55, 56, 57, 58, 59, 
                             60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 
                             70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 
                             80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 
                             90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
   tmpStyle->SetPalette(50, fPaletteColor);

   TString fLineStyleArrayTmp[30] = {"", "  ", " 12 12", " 4 8", 
                             " 12 16 4 16", " 20 12 4 12", " 20 12 4 12 4 12 4 12", " 20 20", " 20 12 4 12 4 12", 
                             " 80 20", " 80 40 4 40", "  ", "  ", "  ", 
                             "  ", "  ", "  ", "  ", "  ", 
                             "  ", "  ", "  ", "  ", "  ", 
                             "  ", "  ", "  ", "  ", "  ", "  "};
   for (Int_t i=0; i<30; i++)
      tmpStyle->SetLineStyleString(i, fLineStyleArrayTmp[i]);

   tmpStyle->SetHeaderPS("");
   tmpStyle->SetTitlePS("");
   tmpStyle->SetFitFormat("6.4f");
   tmpStyle->SetPaintTextFormat("g");
   tmpStyle->SetLineScalePS(3);
   tmpStyle->SetColorModelPS(0);
   tmpStyle->SetTimeOffset(788918400);



   tmpStyle->cd();
   gROOT->ForceStyle();
}
