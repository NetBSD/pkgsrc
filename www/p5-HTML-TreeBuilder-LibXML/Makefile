# $NetBSD: Makefile,v 1.4 2011/08/14 16:05:56 obache Exp $

DISTNAME=	HTML-TreeBuilder-LibXML-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-TreeBuilder-LibXML/
COMMENT=	Perl 5 HTML::TreeBuilder and XPath compatible interface with libxml
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTML/TreeBuilder/LibXML/.packlist

DEPENDS+=	p5-HTML-TreeBuilder-XPath>=0.11:../../www/p5-HTML-TreeBuilder-XPath
DEPENDS+=	p5-XML-LibXML>=1.70:../../textproc/p5-XML-LibXML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
