# $NetBSD: Makefile,v 1.7 2017/06/05 14:25:16 ryoon Exp $

DISTNAME=	Cookie-Baker-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cookie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cookie-Baker/
COMMENT=	Perl extension for cookie string generator/parser
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Time>=0:../../time/p5-Test-Time
DEPENDS+=       p5-URI>=0:../../www/p5-URI

USE_LANGUAGES=	#
PERL5_PACKLIST= auto/Cookie/Baker/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
