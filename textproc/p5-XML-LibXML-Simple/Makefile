# $NetBSD: Makefile,v 1.2 2009/11/26 18:15:35 joerg Exp $
#

DISTNAME=	XML-LibXML-Simple-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-LibXML-Simple/
COMMENT=	XML::LibXML clone of XML::Simple
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-XML-LibXML>=1.64:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=		auto/XML/LibXML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
