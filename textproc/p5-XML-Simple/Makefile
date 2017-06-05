# $NetBSD: Makefile,v 1.36 2017/06/05 14:24:58 ryoon Exp $
#

DISTNAME=	XML-Simple-2.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Simple/
COMMENT=	Easy Perl API to read/write XML
LICENSE=	${PERL5_LICENSE}

# well, XML::SAX >= 0.15 is required, and we distribute 0.99 after a lot of
# out and back in of XML::SAX::Base I tend to require no specific version
DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-SAX-Expat-[0-9]*:../../textproc/p5-XML-SAX-Expat
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-NamespaceSupport>=1.04:../../textproc/p5-XML-NamespaceSupport

PERL5_PACKLIST=		auto/XML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
