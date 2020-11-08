# $NetBSD: Makefile,v 1.30 2020/11/08 03:08:18 mef Exp $

DISTNAME=	XML-LibXML-Iterator-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-LibXML-Iterator
COMMENT=	Iterator for XML::LibXML parsed documents
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-LibXML>=1.52:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-NodeFilter-[0-9]*:../../textproc/p5-XML-NodeFilter

PERL5_PACKLIST=	auto/XML/LibXML/Iterator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
