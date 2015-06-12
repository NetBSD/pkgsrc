# $NetBSD: Makefile,v 1.10 2015/06/12 10:51:39 wiz Exp $

.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2

COMMENT=	CaboCha perl module

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/CaboCha/.packlist

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
