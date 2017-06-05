# $NetBSD: Makefile,v 1.21 2017/06/05 14:24:57 ryoon Exp $
#

DISTNAME=	XML-NodeFilter-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-NodeFilter/
COMMENT=	Object that know how to "filter out" nodes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/NodeFilter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
