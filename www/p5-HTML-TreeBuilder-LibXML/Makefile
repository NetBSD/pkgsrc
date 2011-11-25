# $NetBSD: Makefile,v 1.5 2011/11/25 08:14:54 hiramatsu Exp $

DISTNAME=	HTML-TreeBuilder-LibXML-0.13
PKGNAME=	p5-${DISTNAME}
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
