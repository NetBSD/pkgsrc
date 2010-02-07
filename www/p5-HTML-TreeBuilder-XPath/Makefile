# $NetBSD: Makefile,v 1.1.1.1 2010/02/07 16:38:49 seb Exp $

DISTNAME=	HTML-TreeBuilder-XPath-0.11
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-TreeBuilder-XPath/
COMMENT=	Perl 5 module adding XPath support to HTML::TreeBuilder
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTML/TreeBuilder/XPath/.packlist

DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-XML-XPathEngine>=0.12:../../textproc/p5-XML-XPathEngine

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
