# $NetBSD: Makefile,v 1.17 2018/08/22 09:47:14 wiz Exp $

DISTNAME=	Calendar-Simple-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Calendar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Calendar-Simple/
COMMENT=	Perl extension to create simple calendars
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	#empty
PERL5_PACKLIST= auto/Calendar/Simple/.packlist

PERL5_MODULE_TYPE= Module::Build

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
