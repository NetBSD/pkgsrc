# $NetBSD: buildlink3.mk,v 1.3 2004/09/27 01:07:23 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_GUI_BUILDLINK3_MK:=	${GNUSTEP_GUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-gui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-gui}
BUILDLINK_PACKAGES+=	gnustep-gui

.if !empty(GNUSTEP_GUI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-gui+=		gnustep-gui>=0.9.2
BUILDLINK_RECOMMENDED.gnustep-gui+=	gnustep-gui>=0.9.3nb1
BUILDLINK_PKGSRCDIR.gnustep-gui?=	../../x11/gnustep-gui

PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Bundles\/GSPrinting$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Bundles\/TextConverters$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/AppKit$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/GNUstepGUI$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/gnustep\/gui$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-gui$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-gui\/English.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-gui\/Italian.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/PostScript\/PPD$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/PostScript\/PPD\/English.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Services\/GSspell.service$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Services\/GSspell.service\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Bundles\/GSPrinting$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Bundles\/TextConverters$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/AppKit$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/GNUstepGUI$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/gnustep\/gui$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-gui$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-gui\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/Resources\/gnustep-gui\/Italian.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/PostScript\/PPD$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/PostScript\/PPD\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Services\/GSspell.service$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Services\/GSspell.service\/Resources$$/ { next; }

.endif	# GNUSTEP_GUI_BUILDLINK3_MK

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
