# $NetBSD: buildlink3.mk,v 1.1 2004/04/20 12:33:56 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDEBASE_BUILDLINK3_MK:=	${KDEBASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdebase
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdebase}
BUILDLINK_PACKAGES+=	kdebase

.if !empty(KDEBASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdebase+=	kdebase>=3.2.0
BUILDLINK_RECOMMENDED.kdebase?=	kdebase>=3.2.2
BUILDLINK_PKGSRCDIR.kdebase?=	../../x11/kdebase3
.endif	# KDEBASE_BUILDLINK3_MK

.include "../../databases/openldap/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
