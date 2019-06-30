# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:11 nia Exp $

DISTNAME=	XML-XPathEngine-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-XPathEngine
COMMENT=	Perl 5 re-usable XPath engine for DOM-like trees
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/XML/XPathEngine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
