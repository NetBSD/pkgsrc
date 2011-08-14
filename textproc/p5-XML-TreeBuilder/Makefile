# $NetBSD: Makefile,v 1.3 2011/08/14 15:14:20 obache Exp $

DISTNAME=	XML-TreeBuilder-3.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-TreeBuilder/
COMMENT=	Perl 5 parser that builds a tree of XML::Element objects
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
# The '-' below is not a typo!
PERL5_PACKLIST= auto/XML-TreeBuilder/.packlist

DEPENDS+=	p5-HTML-Tree>=3.08:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
