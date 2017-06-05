# $NetBSD: Makefile,v 1.11 2017/06/05 14:24:59 ryoon Exp $

DISTNAME=	XML-XPathEngine-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-XPathEngine/
COMMENT=	Perl 5 re-usable XPath engine for DOM-like trees
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/XML/XPathEngine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
