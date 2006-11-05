# $NetBSD: Makefile,v 1.16 2006/11/05 16:30:43 joerg Exp $

DISTNAME=	XML-SAX-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX/
COMMENT=	Perl interface to the SAX2 XML Parser

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-XML-NamespaceSupport>=0.03:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/SAX/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${_USE_DESTDIR} != "no"
.include "../../lang/perl5/vars.mk"

INSTALL_ENV+=	PERL5LIB=${DESTDIR}${PERL5_INSTALLVENDORLIB}
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
