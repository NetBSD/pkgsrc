# $NetBSD: Makefile,v 1.3 2012/10/25 06:56:41 asau Exp $
#

DISTNAME=	XML-Tiny-2.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Tiny/
COMMENT=	Simple lightweight parser for a subset of XML
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/XML/Tiny/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
