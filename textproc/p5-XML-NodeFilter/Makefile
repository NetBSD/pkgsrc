# $NetBSD: Makefile,v 1.27 2022/06/28 11:36:42 wiz Exp $
#

DISTNAME=	XML-NodeFilter-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	19
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-NodeFilter
COMMENT=	Object that know how to "filter out" nodes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/NodeFilter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
