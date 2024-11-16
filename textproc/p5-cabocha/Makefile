# $NetBSD: Makefile,v 1.20 2024/11/16 12:07:14 wiz Exp $

PKGREVISION= 8
.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	p5-${DISTNAME}

COMMENT=	CaboCha perl module

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/CaboCha/.packlist

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
