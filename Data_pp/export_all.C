int export_all(void)
{
  TFile *in=new TFile("final_output_10_27_0.59_20.0_5.0.root","read");

  TIter next(in->GetListOfKeys());
  TKey *key;

  while ((key = (TKey*)next()))
    {
      TClass *cl = gROOT->GetClass(key->GetClassName());
      if (cl->InheritsFrom("TH1"))
	{
	  TH1 *h = (TH1*)key->ReadObj();
	  h->SetTitle("");
	  cout<<"histogram name:" <<h->GetName()<<endl;
	}
      if(cl->InheritsFrom("TCanvas"))
	{
	  TCanvas *c= (TCanvas*)key->ReadObj();
	  cout<<"Canvas name"<< c->GetName()<<endl;
	  char name[10000]; // enough to hold all numbers up to 64-bits
	  sprintf(name, "canvas_%s.eps", c->GetName());
	  cout<<"File name "<<name<<endl;
	  //c->SetTitle("");
	  c->SaveAs(name,"recreate");
	  
	}
    } 
  return 0;
}
