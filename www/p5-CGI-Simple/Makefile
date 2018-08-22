# $NetBSD: Makefile,v 1.20 2018/08/22 09:47:31 wiz Exp $

DISTNAME=	CGI-Simple-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Simple/
COMMENT=	Simple totally OO CGI interface that is CGI.pm compliant
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
