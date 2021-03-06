//
//  FraisTableViewController.h
//  Phileas_Gestion
//
//  Created by Florent&Romain on 23/04/2015.
//  Copyright (c) 2015 Florent&Romain. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#import "AppDelegate.h"
#import "IndemnitesTableViewController.h"
#import "Type+DataModel.h"
#import "Frais+DataModel.h"
#import "IndemniteK+DataModel.h"
#import "BaremeAuto+DataModel.h"
#import "User+DataModel.h"
#import "Draft.h"
#import "Expense-def.h"
#import "Message.h"

@interface FraisTableViewController : UITableViewController <NSFetchedResultsControllerDelegate, UIAlertViewDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate, CLLocationManagerDelegate>

// ===== AppDelegate et context pour le CoreData =====
@property (weak, nonatomic) AppDelegate* appDelegate;
@property (weak, nonatomic) NSManagedObjectContext *context;

// ===== Variables utilisées pour la géolocalisation =====
@property (strong, nonatomic) CLLocationManager *locationManager;
@property (strong, nonatomic) CLGeocoder *geocoder;
@property (strong, nonatomic) CLPlacemark *placemark;

// ===== Autres variables =====
/**
 * @brief Un tableau qui va contenir la liste des type de frais.
 */
@property (strong, nonatomic) NSArray* listeType;

/**
 * @brief Une chaîne de caractère contenant le montant du frais.
 */
@property (strong, nonatomic) NSMutableString* montant;

/**
 * @brief L'indemnité kilomètrique du frais si elle existe.
 */
@property (strong, nonatomic) IndemniteK* indemniteK;

/**
 * @brief Le frais qui va être créé ou modifié.
 */
@property (strong, nonatomic) Frais* fraisChoisi;

/**
 * @brief L'utilisateur connecté.
 */
@property (strong, nonatomic) User* utilisateur;

/**
 * @brief Un tableau qui va contenir la liste des expense-def récupérée depuis la BD.
 */
@property (strong, nonatomic) NSArray* listeExpenseDef;

// ===== Outlets =====
@property (weak, nonatomic) IBOutlet UINavigationItem *navBar;
@property (weak, nonatomic) IBOutlet UITextField *dateTexte;
@property (weak, nonatomic) IBOutlet UILabel *localisationLbl;
@property (weak, nonatomic) IBOutlet UIButton *typeF;
@property (weak, nonatomic) IBOutlet UITextField *montantTextField;
@property (strong, nonatomic) IBOutlet UIButton *modifierIndemnite;
@property (weak, nonatomic) IBOutlet UITextView *comTextArea;
@property (weak, nonatomic) IBOutlet UIImageView *image;
@property (weak, nonatomic) IBOutlet UIButton *saisirButton;

@property (strong, nonatomic) UIDatePicker *pickerViewDate;
@property (strong, nonatomic) NSDate *dateToChoose;

// ===== Actions =====
/**
 * @brief Cette fonction permet de lancer une alerte au clic sur le bouton changerType afin de choisir le type du frais parmis la liste de tous les types.
 */
- (IBAction)changerType:(id)sender;

/**
 * @brief Cette fonction permet de lancer une alerte au clic sur le bouton justificatif pour choisir de prendre une photo ou de sélectionner une image dans la librairie.
 */
- (IBAction)choisirImage:(id)sender;

/**
 * @brief Cette fonction sert à sauvegarder le brouillon en local au clic sur le bouton saisir ou à modifier un brouillon au clic sur le bouton modifier.
 */
- (IBAction)saisir:(id)sender;

/**
 * @brief Cette fonction permet d'envoyer le brouillon à l'application web de phileas.
 * @brief Cette fonction utilise le framework RestKit et la fonction draft de l'api de phileas.
 */
- (IBAction)envoyer:(id)sender;

// ===== Methods =====
/**
 * @brief Cette fonction sert à récupérer les différents types de frais possibles depuis la BD phileas et à les stocker sur l'appareil.
 * @brief Les types de frais sont créés uniquement s'il n'existe pas déjà sur l'appareil, donc au premier lancement de l'application.
 */
- (void)creerTypesFrais;

/**
 * @brief Cette fonction sert à créer les différents barèmes kilométriques et à les stocker sur l'appareil.
 * @brief Les barèmes kilométriques sont créés uniquement s'il n'existe pas déjà sur l'appareil, donc au premier lancement de l'application.
 * @brief Il sera nécessaire de modifier les différents chiffres chaque année.
 */
- (void)creerBaremesAuto;

/**
 * @brief Cette fonction permet de charger depuis le coreData tous les types de frais existant.
 */
- (void)chargerListeTypesFrais;

/**
 * @brief Cette fonction permet de changer la date du frais après l'avoir sélectionnée dans un datePicker.
 */
-(void)changerDeDate:(UIDatePicker *)sender;

/**
 * @brief Cette fonction sert à récupérer le nombre de messages récents afin d'afficher un badge sur les notifications.
 * @brief Elle utilise la class message et la fonction message de l'api.
 */
- (void) compterNotifs;

@end