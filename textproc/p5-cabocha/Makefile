# $NetBSD: Makefile,v 1.11 2016/06/08 19:24:47 wiz Exp $

.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3

COMMENT=	CaboCha perl module

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/CaboCha/.packlist

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
