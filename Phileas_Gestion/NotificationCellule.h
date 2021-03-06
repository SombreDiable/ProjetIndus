//
//  NotificationCellule.h
//  Phileas_Gestion
//
//  Created by Florent on 11/05/2015.
//  Copyright (c) 2015 Florent&Romain. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * @brief Cette classe sert à remplir le contenu présent sur chaque ligne du tableView notifications.
 */
@interface NotificationCellule : UITableViewCell

// ===== Outlets =====
@property (nonatomic, weak) IBOutlet UILabel *titreLabel;
@property (nonatomic, weak) IBOutlet UILabel *dateLabel;
@property (nonatomic, weak) IBOutlet UILabel *msgLabel;

@end
