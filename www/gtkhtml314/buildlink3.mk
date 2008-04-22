# $NetBSD: buildlink3.mk,v 1.7 2008/04/22 05:59:12 wiz Exp $

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
BUILDLINK_ABI_DEPENDS.gtkhtml314?=	gtkhtml314>=3.18
BUILDLINK_PKGSRCDIR.gtkhtml314?=	../../www/gtkhtml314
.endif	# GTKHTML314_BUILDLINK3_MK

# XXX: gail is not required by the .pc file but appears as a library
# '-lgailutil' in the .la file...  I'm not sure about putting the dependency
# here.
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
