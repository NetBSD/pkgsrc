# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:30 wiz Exp $

BUILDLINK_TREE+=	passenger

.if !defined(PASSENGER_BUILDLINK3_MK)
PASSENGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.passenger+=	${RUBY_PKGPREFIX}-passenger>=5.1
BUILDLINK_ABI_DEPENDS.passenger?=		${RUBY_PKGPREFIX}-passenger>=5.3.7nb15
BUILDLINK_PKGSRCDIR.passenger?=		../../www/passenger

BUILDLINK_INCDIRS.passenger+=		share/passenger/include
BUILDLINK_INCDIRS.passenger+=		share/passenger/ngx_http_passenger_module

.include "../../lang/ruby/rubyversion.mk"
.endif # PASSENGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-passenger
