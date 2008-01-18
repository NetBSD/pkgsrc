# $NetBSD: buildlink3.mk,v 1.14 2008/01/18 05:09:55 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_GUI_BUILDLINK3_MK:=	${GNUSTEP_GUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-gui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-gui}
BUILDLINK_PACKAGES+=	gnustep-gui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnustep-gui

.if !empty(GNUSTEP_GUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnustep-gui+=	gnustep-gui>=0.9.2
BUILDLINK_ABI_DEPENDS.gnustep-gui+=	gnustep-gui>=0.12.0nb1
BUILDLINK_PKGSRCDIR.gnustep-gui?=	../../x11/gnustep-gui

PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Bundles\/GSPrinting$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Bundles\/TextConverters$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/AppKit$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/GNUstepGUI$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Headers\/gnustep\/gui$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/gnustep-gui\/Versions\/0\.12\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/gnustep-gui\/Versions\/0\.12\/Resources\/English.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Libraries\/gnustep-gui\/Versions\/0\.12\/Resources\/Italian.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/PostScript\/PPD$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/PostScript\/PPD\/English.lproj$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Services\/GSspell.service$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/GNUstep\/System\/Library\/Services\/GSspell.service\/Resources$$/ { print "@comment in x11/gnustep-gui: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Bundles\/GSPrinting$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Bundles\/TextConverters$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/AppKit$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/GNUstepGUI$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Headers\/gnustep\/gui$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/gnustep-gui\/Versions\/0\.12\/Resources$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/gnustep-gui\/Versions\/0\.12\/Resources\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Libraries\/gnustep-gui\/Versions\/0\.12\/Resources\/Italian.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/PostScript\/PPD$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/PostScript\/PPD\/English.lproj$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Services\/GSspell.service$$/ { next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/share\/GNUstep\/System\/Library\/Services\/GSspell.service\/Resources$$/ { next; }

.endif	# GNUSTEP_GUI_BUILDLINK3_MK

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
