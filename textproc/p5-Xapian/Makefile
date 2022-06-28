# $NetBSD: Makefile,v 1.11 2022/06/28 11:36:46 wiz Exp $

PKGNAME=		p5-${PKGNAME_MODULE:S/^x/X/}
PKGREVISION=		1
COMMENT=		Perl bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/perl/

USE_TOOLS+=		perl

CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		PERL_ARCH=${PERL5_INSTALLVENDORARCH:Q}
CONFIGURE_ENV+=		PERL_LIB=${PERL5_INSTALLVENDORLIB:Q}

REPLACE_PERL=		perl/docs/examples/*.pl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PERL_DLEXT=		bundle
.else
PERL_DLEXT=		so
.endif
PLIST_SUBST+=		PERL_DLEXT=${PERL_DLEXT}

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/perl/examples/*.pl

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/dirs.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
