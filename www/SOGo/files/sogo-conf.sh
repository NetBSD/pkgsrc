#!/bin/sh

su -m @SOGOUSER@ << EOT
mkdir -p ~@SOGOUSER@/GNUstep/Defaults

defaults write sogod SOGoTimeZone "Europe/Paris"
defaults write sogod SOGoMailDomain "example.net"
defaults write sogod SOGoLanguage French
defaults write sogod SOGoAppointmentSendEMailNotifications YES 
defaults write sogod SOGoFoldersSendEMailNotifications YES 
defaults write sogod SOGoACLsSendEMailNotifications YES 

defaults write sogod SOGoUserSources '({
	CNFieldName = cn; 
	IDFieldName = uid;
	UIDFieldName = uid;
	IMAPHostFieldName = netExampleMailhost; 
	baseDN = "dc=example,dc=net";
	bindDN = "";
	bindPassword = "";
	canAuthenticate = YES;
	displayName = "ExampleNet SARL";
	bindFields = (uid);
	hostname = "ldap.example.net"; 
	id = public; 
	isAddressBook = YES; 
	port = 636;
	encryption = SSL;
	filter = "(objectClass='inetOrgPerson')";
})' 
defaults write sogod SOGoProfileURL 'mysql://sogo:sogo@localhost/sogo/sogo_user_profile' 
defaults write sogod OCSFolderInfoURL 'mysql://sogo:sogo@localhost/sogo/sogo_folder_info' 
defaults write sogod OCSSessionsFolderURL 'mysql://sogo:sogo@localhost/sogo/sogo_sessions_folder' 

defaults write sogod SOGoMailingMechanism smtp 
defaults write sogod SOGoSMTPServer smtp.example.net

defaults write sogod SOGoDraftsFolderName Drafts 
defaults write sogod SOGoSentFolderName Sent 
defaults write sogod SOGoTrashFolderName Trash 
defaults write sogod SOGoIMAPServer imaps://localhost:993 

defaults write sogod SOGoPageTitle "Agenda "ExampleNet SARL"
defaults write sogod SOGoLoginModule "Calendar"
defaults write sogod SOGoZipPath "/usr/pkg/bin/zip"

EOT

/etc/rc.d/sogod restart
