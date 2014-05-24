#ifndef MAINSETTINGSDIALOG_H
#define MAINSETTINGSDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QHash>
#include <QList>
#include <QSettings>
#include <QMap>

#include "autoprofileinfo.h"
#include "inputdevice.h"
#include "antimicrosettings.h"

namespace Ui {
class MainSettingsDialog;
}

class MainSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainSettingsDialog(AntiMicroSettings *settings, QList<InputDevice*> *devices, QWidget *parent = 0);
    ~MainSettingsDialog();

protected:
    void fillControllerMappingsTable();
    void insertTempControllerMapping(QHash<QString, QList<QVariant> > &hash, QString newGUID);
    void checkLocaleChange();
    void findLocaleItem();
    void populateAutoProfiles();
    void fillAutoProfilesTable(QString guid);
    void fillAllAutoProfilesTable();
    void clearAutoProfileData();

    AntiMicroSettings *settings;
    QMap<QString, AutoProfileInfo*> defaultAutoProfiles;
    QMap<QString, QList<AutoProfileInfo*> > deviceAutoProfiles;
    QMap<QString, QList<AutoProfileInfo*> > exeAutoProfiles;
    //QMap<QString, QList<AutoProfileInfo*> > totalAutoProfiles;
    QList<AutoProfileInfo*> defaultList;
    QList<AutoProfileInfo*> profileList;

    AutoProfileInfo* allDefaultProfile;
    QList<InputDevice*> *connectedDevices;
    //QList<QString> discoveredGuids;

    //QHash<QString, QHash<QString, QString> > deviceAutoProfiles;
    //QHash<QString, QList<QHash<QString, QString> > > defaultAutoProfiles;
    //QHash<QString,

    //QHash<QString, QList<QHash<QString, QString> > > appProfileAssignments;
    //QHash<QString, QHash<QString, QString> > defaultProfileAssignments;

private:
    Ui::MainSettingsDialog *ui;

signals:
    void changeLanguage(QString language);

protected slots:
    void mappingsTableItemChanged(QTableWidgetItem *item);
    void insertMappingRow();
    void deleteMappingRow();
    void syncMappingSettings();
    void saveNewSettings();
    void selectDefaultProfileDir();
    void fillGUIDComboBox();
    void changeDeviceForProfileTable(int index);
    void saveAutoProfileSettings();
    void processAutoProfileActiveClick(QTableWidgetItem *item);
    void openAddAutoProfileDialog();
    void openEditAutoProfileDialog();
    void openDeleteAutoProfileConfirmDialog();
    void changeAutoProfileButtonsState();
    void transferEditsToCurrentTableRow();
    void transferAllProfileEditToCurrentTableRow();
    void addNewAutoProfile();
    void autoProfileButtonsActiveState(bool enabled);
    void changeKeyRepeatWidgetsStatus(bool enabled);
};

#endif // MAINSETTINGSDIALOG_H
