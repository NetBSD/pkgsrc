# $NetBSD: Makefile,v 1.2 2005/04/11 21:47:40 tv Exp $

DISTNAME=	XML-SAX-Writer-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX-Writer/
COMMENT=	SAX2 (XML) Writer

DEPENDS+=	p5-XML-NamespaceSupport>=0.03:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/SAX/Writer/.packlist
MAKE_ENV+=		PERL5LIB="${PREFIX}/${PERL5_SUB_INSTALLSITELIB}"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
