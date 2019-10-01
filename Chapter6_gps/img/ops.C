/*
 * Uzycie:
 * root
 * .L 3gammaPsBarrel.C
 * draw()
 *
*/

double Rad2Deg(double angle){
  return 180.*angle/TMath::Pi();
}

TGeoVolume * MakeLine(TVector3 A, TVector3 B, TGeoManager * geom, int color){

  TVector3 p = (B-A)*0.5.;

  double length = p.Mag();

  TGeoMedium *fake=new TGeoMedium("fake3",0,new TGeoMaterial("Fake3",0,0,0));

  TGeoVolume *arrow=geom->MakeTube("arrow",fake,0.,1.5, length);
  arrow->SetLineColor(color);
  geom->GetTopVolume()->AddNodeOverlap(arrow,1,
				       new TGeoCombiTrans(A.X()+p.X(),
							  A.Y()+p.Y(),
							  A.Z()+p.Z(),
					 new TGeoRotation("rot2",
							  Rad2Deg(p.Phi())+90,		  
							  Rad2Deg(p.Theta()),
							  0)
							  )
				       );
  
  return arrow;
}

/**
 * glowna funkcja do wyolania z ROOT-a
 */
void draw(){

  int N = 48;
  float R = 200;
  float R2 = 224;
  float R3 = 268;
  float z_pos = 20.;
  float scinDim[3] = {2,5,120};
  float plane_incline = -15.; // deg.
  TVector3 decayPs(47.,0,z_pos);
  TVector3 decaySrc = decayPs;
  /* TVector3 decaySrc(-20,-20,z_pos); */
  int hit_scins[3] = {19, 34, 11};
  int hit_color[3] = {2, kOrange, 6};
  //  int tag_scin = 30;
  int tag_scin = 45;
  float tag_z = -120.;

  TVector3 hits[3];


  TGeoManager *geom=new TGeoManager("geom","My first 3D geometry");

  TGeoMaterial *vacuum=new TGeoMaterial("vacuum",0,0,0);
  TGeoMedium *Air=new TGeoMedium("Vacuum",0,vacuum);

  TGeoMedium *plastic=new TGeoMedium("plastic",0,new TGeoMaterial("Plastic",0,0,0));
  plastic->GetMaterial()->SetTransparency(0);

  TGeoMedium *fake=new TGeoMedium("fake",0,new TGeoMaterial("Fake",0,0,0));
  fake->GetMaterial()->SetTransparency(50);

  TGeoMedium *fake2=new TGeoMedium("fake2",0,new TGeoMaterial("Fake2",0,0,0));
  TGeoMedium *fake3=new TGeoMedium("fake3",0,new TGeoMaterial("Fake3 ",0,0,0));

  TGeoVolume *top=geom->MakeBox("top",Air,1000.,1000.,1000.);
  geom->SetTopVolume(top);
  geom->SetTopVisible(0);

  for(int i=0;i<N;i++){
    TGeoVolume *scin=geom->MakeBox(Form("scin%d",i),plastic, scinDim[0], scinDim[1], scinDim[2] );
    scin->SetFillColor(7);
    scin->SetLineColor(7);
    top->AddNodeOverlap(scin,1,new TGeoCombiTrans(R*TMath::Sin(2.*TMath::Pi()*i/N),
						  R*TMath::Cos(2.*TMath::Pi()*i/N),
						  0,
						  new TGeoRotation("rot1",0,0,-360.*i/N)));
    // hit points
    
    if( i==hit_scins[0] ){
      TGeoVolume *inters=geom->MakeBox(Form("inters%d",i),fake3,scinDim[0]+1,scinDim[1]+1,10.);
      inters->SetLineColor(hit_color[0]);
      
      TGeoRotation * rot = new TGeoRotation("rot4",0,0,0);
      top->AddNodeOverlap(inters,1,new TGeoCombiTrans(R*TMath::Sin(2.*TMath::Pi()*i/N),
						      R*TMath::Cos(2.*TMath::Pi()*i/N),
						      z_pos-R*TMath::Sin(2.*TMath::Pi()*i/N) * TMath::Tan( (TMath::Pi()/180.) * plane_incline ),
						      new TGeoRotation("rot5", 0,0,-360.*i/N)));
    }

  }


  // second layer
  for(int i=0;i<N;i++){
    TGeoVolume *scin=geom->MakeBox(Form("scin%d",i),plastic, scinDim[0], scinDim[1], scinDim[2] );
    scin->SetFillColor(7);
    scin->SetLineColor(7);
    top->AddNodeOverlap(scin,1,new TGeoCombiTrans(R2*TMath::Sin(2.*TMath::Pi()*i/N+3.75*TMath::Pi()/180.),
						  R2*TMath::Cos(2.*TMath::Pi()*i/N+3.75*TMath::Pi()/180.),
						  0,
						  new TGeoRotation("rot1",0,0,-360.*i/N)));

    // hit point
    if( i==hit_scins[1] ){
      TGeoVolume *inters=geom->MakeBox(Form("inters%d",i),fake3,scinDim[0]+1,scinDim[1]+1,7.);
      inters->SetLineColor(hit_color[1]);
      
      TGeoRotation * rot = new TGeoRotation("rot4",0,0,0);
      top->AddNodeOverlap(inters,1,new TGeoCombiTrans(R2*TMath::Sin(2.*TMath::Pi()*i/N+3.75*TMath::Pi()/180.),
						      R2*TMath::Cos(2.*TMath::Pi()*i/N+3.75*TMath::Pi()/180.),
						      z_pos-R2*TMath::Sin(2.*TMath::Pi()*i/N) * TMath::Tan( (TMath::Pi()/180.) * plane_incline ),
						      new TGeoRotation("rot5", 0,0,-360.*i/N)));
    }
    
  }

  // third layer
  for(int i=0;i<2*N;i++){
    TGeoVolume *scin=geom->MakeBox(Form("scin%d",i),plastic, scinDim[0], scinDim[1], scinDim[2] );
    scin->SetFillColor(7);
    scin->SetLineColor(7);
    top->AddNodeOverlap(scin,1,new TGeoCombiTrans(R3*TMath::Sin(2.*TMath::Pi()*i/(2*N)+1.185*TMath::Pi()/180.),
						  R3*TMath::Cos(2.*TMath::Pi()*i/(2*N)+1.185*TMath::Pi()/180.),
						  0,
						  new TGeoRotation("rot1",0,0,-360.*i/(2*N))));

    // hit point
    if( i==hit_scins[2] ){
      TGeoVolume *inters=geom->MakeBox(Form("inters%d",i),fake3,scinDim[0]+1,scinDim[1]+1,7.);
      inters->SetLineColor(hit_color[2]);
      
      TGeoRotation * rot = new TGeoRotation("rot4",0,0,0);
      top->AddNodeOverlap(inters,1,new TGeoCombiTrans(R3*TMath::Sin(2.*TMath::Pi()*i/(2*N)+1.185*TMath::Pi()/180.),
						      R3*TMath::Cos(2.*TMath::Pi()*i/(2*N)+1.185*TMath::Pi()/180.),
						      z_pos-R3*TMath::Sin(2.*TMath::Pi()*i/(2*N)+1.185*TMath::Pi()/180.) * TMath::Tan( (TMath::Pi()/180.) * plane_incline ),
						      new TGeoRotation("rot5", 0,0,-360.*i/(2*N))));
    }
    
  }

  TGeoVolume *plane=geom->MakeTube(Form("plane",i),fake, 0., 1.05*R3,0.);
  plane->SetLineColor(17);
  TGeoRotation * rot = new TGeoRotation("rot4",0,0,0);
  rot->RotateY(plane_incline);
  top->AddNodeOverlap(plane,1,new TGeoCombiTrans(0,
						 0,
						 z_pos,
						 rot));

  
  TGeoVolume *decayPsPoint=geom->MakeSphere("decayPsPoint",fake2,0.,7.);
  decayPsPoint->SetFillColor(1);
  decayPsPoint->SetLineColor(1);
  top->AddNodeOverlap(decayPsPoint,1,
		      new TGeoTranslation(decayPs.X(),
					 decayPs.Y(),
					 decayPs.Z()
					 ));

  TGeoVolume *decaySrcPoint=geom->MakeSphere("decaySrcPoint",fake2,0.,7.);
  decaySrcPoint->SetFillColor(1);
  decaySrcPoint->SetLineColor(1);
  top->AddNodeOverlap(decaySrcPoint,1,
		      new TGeoTranslation(decaySrc.X(),
					 decaySrc.Y(),
					 decaySrc.Z()
					 ));



  for(int i=0;i<3;i++){

    int nn = (i==2 ? 2*N : N);
    float rr = (i==2 ? R3 : (i==1 ? R2 : R));
    float shift_rad = (i==2 ? 1.185 : (i==1 ? 3.75 : 0.0));
    shift_rad *= TMath::Pi() / 180.;
    float angle = (2.*TMath::Pi()/nn)*hit_scins[i] + shift_rad;
    hits[i].SetX( (rr-scinDim[0])*TMath::Sin( angle ) );
    hits[i].SetY( (rr-scinDim[0])*TMath::Cos( angle ) );
    hits[i].SetZ( z_pos  - hits[i].X() * TMath::Tan( (TMath::Pi()/180.) * plane_incline )  );

    MakeLine(decayPs, hits[i], geom, hit_color[i]);
  }
  
  // draw tag hit
  float angle = (2.*TMath::Pi()/N)*tag_scin[i];
  TVector3 tag;
  tag.SetX( (R-scinDim[0])*TMath::Sin( angle ) );
  tag.SetY( (R-scinDim[0])*TMath::Cos( angle ) );
  tag.SetZ( tag_z  );
  //  MakeLine(decaySrc, tag, geom)->SetLineColor(kOrange);
  /* TGeoVolume *hitPoint=geom->MakeSphere("hitPoint",fake2,0.,10.); */
  /* hitPoint->SetLineColor(2); */
  /* top->AddNodeOverlap(hitPoint,1, */
  /* 		      new TGeoCombiTrans(tag.X(), */
  /* 					 tag.Y(), */
  /* 					 tag.Z(), */
  /* 					 new TGeoRotation("rot1",0,0,0))); */
  
  // mark tag hit on scintillator
  //  TGeoVolume *inters=geom->MakeBox("inters4",fake3,scinDim[0]+1,scinDim[1]+1,7.);
  //  inters->SetLineColor(kRed);
  
  //  TGeoRotation * rot = new TGeoRotation("rot4",0,0,0);
  // rot->RotateZ(-360.*tag_scin/N);
  // top->AddNodeOverlap(inters,1,new TGeoCombiTrans(R*TMath::Sin(2.*TMath::Pi()*tag_scin/N),
  // 						  R*TMath::Cos(2.*TMath::Pi()*tag_scin/N),
  // 						  tag_z,
  // 						  rot));
  
  

  geom->CloseGeometry();
  top->Draw("ogl");

}
