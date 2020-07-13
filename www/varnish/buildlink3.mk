# $NetBSD: buildlink3.mk,v 1.1 2020/07/13 18:43:22 wiz Exp $

BUILDLINK_TREE+=	varnish

.if !defined(VARNISH_BUILDLINK3_MK)
VARNISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.varnish+=	varnish>=3.0.6nb3
BUILDLINK_PKGSRCDIR.varnish?=	../../www/varnish
BUILDLINK_INCDIRS.varnish=	include/varnish
BUILDLINK_LIBDIRS.varnish=	lib/varnish

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"

.endif	# VARNISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-varnish
