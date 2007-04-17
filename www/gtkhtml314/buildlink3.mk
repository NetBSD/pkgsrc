# $NetBSD: buildlink3.mk,v 1.2 2007/04/17 11:26:11 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHTML314_BUILDLINK3_MK:=	${GTKHTML314_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml314
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml314}
BUILDLINK_PACKAGES+=	gtkhtml314
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkhtml314

.if !empty(GTKHTML314_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkhtml314+=	gtkhtml314>=3.14.0
BUILDLINK_PKGSRCDIR.gtkhtml314?=	../../www/gtkhtml314
.endif	# GTKHTML314_BUILDLINK3_MK

# XXX: gail is not required by the .pc file but appears as a library
# '-lgailutil' in the .la file...  I'm not sure about putting the dependency
# here.
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
