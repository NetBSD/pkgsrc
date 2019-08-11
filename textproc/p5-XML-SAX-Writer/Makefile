# $NetBSD: Makefile,v 1.28 2019/08/11 13:23:56 wiz Exp $

DISTNAME=	XML-SAX-Writer-0.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-SAX-Writer
COMMENT=	SAX2 (XML) Writer
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.8.8,p5-Encode>=2.12}:../../textproc/p5-Encode
DEPENDS+=	p5-XML-SAX>=0.11:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-NamespaceSupport>=1.00:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-XML-Filter-BufferText>=1.00:../../textproc/p5-XML-Filter-BufferText

PERL5_PACKLIST=		auto/XML/SAX/Writer/.packlist
MAKE_ENV+=		PERL5LIB="${PREFIX}/${PERL5_SUB_INSTALLSITELIB}"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
