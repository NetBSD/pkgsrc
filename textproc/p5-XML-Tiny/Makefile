# $NetBSD: Makefile,v 1.4 2013/05/31 12:42:22 wiz Exp $
#

DISTNAME=	XML-Tiny-2.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
