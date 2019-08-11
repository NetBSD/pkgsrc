# $NetBSD: Makefile,v 1.40 2019/08/11 13:23:56 wiz Exp $

DISTNAME=	XML-Simple-2.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Simple
COMMENT=	Easy Perl API to read/write XML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-SAX-Expat-[0-9]*:../../textproc/p5-XML-SAX-Expat
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-NamespaceSupport>=1.04:../../textproc/p5-XML-NamespaceSupport

PERL5_PACKLIST=		auto/XML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
