# $NetBSD: buildlink3.mk,v 1.18 2009/04/13 12:21:37 rh Exp $

BUILDLINK_TREE+=	gnustep-back

.if !defined(GNUSTEP_BACK_BUILDLINK3_MK)
GNUSTEP_BACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-back+=	gnustep-back>=0.9.2
BUILDLINK_ABI_DEPENDS.gnustep-back+=	gnustep-back>=0.12.0nb1
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back

PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle$$/ { print "@comment in x11/gnustep-back: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle\/Resources$$/ { print "@comment in x11/gnustep-back: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle\/Resources\/English.lproj$$/ { print "@comment in x11/gnustep-back: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle\/Resources\/Swedish.lproj$$/ { print "@comment in x11/gnustep-back: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Fonts$$/ { print "@comment in x11/gnustep-back: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/GNUstep\/Fonts\/Helvetica.nfont$$/ { print "@comment in x11/gnustep-back: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle\/Resources\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Bundles\/libgnustep-back-016.bundle\/Resources\/Swedish.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Fonts$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/lib\/GNUstep\/Fonts\/Helvetica.nfont$$/ { next; }

.include "../../x11/gnustep-gui/buildlink3.mk"
.endif # GNUSTEP_BACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-back
