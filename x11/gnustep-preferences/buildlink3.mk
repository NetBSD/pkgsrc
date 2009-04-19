# $NetBSD: buildlink3.mk,v 1.14 2009/04/19 09:29:57 rh Exp $

BUILDLINK_TREE+=	gnustep-preferences

.if !defined(GNUSTEP_PREFERENCES_BUILDLINK3_MK)
GNUSTEP_PREFERENCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-preferences+=	gnustep-preferences>=1.2.0nb19
BUILDLINK_PKGSRCDIR.gnustep-preferences?=	../../x11/gnustep-preferences

BUILDLINK_INCDIRS.gnustep-preferences+=	lib/GNUstep/Frameworks/PrefsModule.framework/Headers
BUILDLINK_FILES.gnustep-preferences+=	lib/GNUstep/Frameworks/PrefsModule.framework/Headers/*.h
BUILDLINK_FILES.gnustep-preferences+= 	include/PrefsModule/PrefsModule.h

PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Applications\/Preferences.app$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Applications\/Preferences.app\/Resources$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Applications\/Preferences.app\/Resources\/English.lproj$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Applications\/Preferences.app\/Resources\/PrefsApp.prefs$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Applications\/Preferences.app\/Resources\/PrefsApp.prefs\/Resources$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Frameworks\/PrefsModule.framework$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions\/0$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions\/0\/Headers$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions\/0\/Resources$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Preferences$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Preferences\/Keyboard.prefs$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Preferences\/Keyboard.prefs\/Resources$$/ { print "@comment in x11/gnustep-preferences: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Applications\/Preferences.app$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Applications\/Preferences.app\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Applications\/Preferences.app\/Resources\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Applications\/Preferences.app\/Resources\/PrefsApp.prefs$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Applications\/Preferences.app\/Resources\/PrefsApp.prefs\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Frameworks\/PrefsModule.framework$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions\/0$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions\/0\/Headers$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Frameworks\/PrefsModule.framework\/Versions\/0\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Preferences$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Preferences\/Keyboard.prefs$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Preferences\/Keyboard.prefs\/Resources$$/ { next; }

#.include "../../x11/gnustep-back/buildlink3.mk"
.endif	# GNUSTEP_PREFERENCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-preferences
