# $NetBSD: Makefile,v 1.25 2012/07/06 12:49:04 sno Exp $
#

DISTNAME=	XML-Simple-2.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xsi
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Simple/
COMMENT=	Easy Perl API to read/write XML
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# well, XML::SAX >= 0.15 is required, and we distribute 0.99 after a lot of
# out and back in of XML::SAX::Base I tend to require no specific version
DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-SAX-Expat-[0-9]*:../../textproc/p5-XML-SAX-Expat
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-NamespaceSupport>=1.04:../../textproc/p5-XML-NamespaceSupport

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
