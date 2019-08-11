# $NetBSD: Makefile,v 1.18 2019/08/11 13:24:52 wiz Exp $

DISTNAME=	Kwiki-Zipcode-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki Zipcode Plugin

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Zipcode/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
