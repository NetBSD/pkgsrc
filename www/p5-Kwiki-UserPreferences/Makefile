# $NetBSD: Makefile,v 1.28 2023/07/06 09:42:46 wiz Exp $

DISTNAME=	Kwiki-UserPreferences-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki user preferences plugin

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/UserPreferences/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
